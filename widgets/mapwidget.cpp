#include "mapwidget.h"
#include "ui_mapwidget.h"

#include <utils/converter.h>
#include "settings.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    prevSize = this->size();
    availableBackgrounds<<":/schemes/img/kkt.jpg"<<":/schemes/img/saz.jpg"<<":/schemes/img/ssp.jpg"<<":/schemes/img/laskarzew.jpg";
    Global::authorization->addInterface(this);
    AuthorizationInterface::addOnLogIn(ui->widgetXY);
}

void MapWidget::setInputsCount(int count) {
    clearLayout(ui->contentLayout);
    QWidget* toAdd = new QWidget(ui->contentWidget);
    toAdd->setLayout(new QVBoxLayout(ui->contentWidget));
    ui->contentLayout->addWidget(toAdd);
    for(int i=1; i<=count; i++) {
        tinyInputs.push_back(new TinyInput(i, ui->tinyInputWidget));
        toAdd->layout()->addWidget(tinyInputs.last());
        if(i%32==0 && i!=count) {
            toAdd = new QWidget(ui->contentWidget);
            toAdd->setLayout(new QVBoxLayout(ui->contentWidget));
            ui->contentLayout->addWidget(toAdd);
        }
    }
}

QString MapWidget::getBackgroundPath() const
{
    return availableBackgrounds.at(bgId);
}

int MapWidget::getBackgroundId() const {
    return bgId;
}

MalfunctionWidget& MapWidget::getMalfunctionWidget() {
    return *ui->malfunctionWidget;
}

void MapWidget::setConnectionID(int value)
{
    connectionID = value;
}

QStringList MapWidget::getAvailableBackgrounds() const
{
    return availableBackgrounds;
}

void MapWidget::mousePressEvent(QMouseEvent *event)
{
    if(adderState) {
        createInput(event->localPos());
        adderState=false;
    }
}

void MapWidget::createInput(const QPointF& _pos, const QString& _name, int id, int dbID, int type)
{
    auto *point = new Inputs(_name, id, this);
    if(dbID!=-1) { //Jeżeli punkt jest ładowany
        point->setPos(
                    Converter::toDefault(
                        QPoint(
                            settings.mapResolution.get(),
                            settings.mapResolution.get()
                            ),
                        Converter::sizeToPoint(this->size()), _pos)
                    ,14);
        point->setDbID(dbID);
        point->setSensorType(static_cast<Inputs::Type>(type));
    } else { //Jeżeli punkt jest tworzony
        QPointF qpoint = Converter::toDefault(
                    Converter::sizeToPoint(
                        this->size()
                        ),
                    QPoint(settings.mapResolution.get(),
                           settings.mapResolution.get()),
                    _pos
                    );

        if(database!=nullptr)
            point->setDbID(database->addInput(*point, connectionID, qpoint));
        else
            point->setDbID(dbID);
        point->setPos(_pos);
    }

    connect(point, &Inputs::editEmited, this, &MapWidget::showEditDialog);
    connect(point, &Inputs::saveMe, this, &MapWidget::saveInput);
    inputs.append(point);
    point->show();
}

void MapWidget::setBackground(int id) {
    if(id>=availableBackgrounds.count()) return;
    bgId = id;
    this->setStyleSheet("#centralWidget{border-image: url("+availableBackgrounds.at(id)+") 0 0 0 0 stretch stretch;}");
}

void MapWidget::passDatabase(Database &db, int connid)
{
    database=&db;
    setConnectionID(connid);
    QSqlQueryModel *model = database->getAllInputs(connid);
    for(int i = 0; i < model->rowCount(); ++i)
    {
        createInput(
                    QPointF(model->record(i).value(5).toReal(), model->record(i).value(6).toReal()),
                    model->record(i).value(1).toString(),
                    model->record(i).value(2).toInt(),
                    model->record(i).value(0).toInt(),
                    model->record(i).value(3).toInt());
    }

}

void MapWidget::showEditDialog(Inputs& _input) {
    InputEditDialog* dialog = new InputEditDialog(_input, tinyInputs.count(), this);
    dialog->show();
}

void MapWidget::saveInput(Inputs &_input)
{
    if(database!=nullptr)
        database->updateInput(_input);
}

MapWidget::~MapWidget()
{
    delete ui;
}

void MapWidget::on_addButton_clicked()
{
    adderState=!adderState;
}

void MapWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    foreach(auto point, inputs)
        point->setPos(Converter::toCurrent(this->size(), prevSize, point->getPosition()));

    prevSize = this->size();
}

void MapWidget::updateInputStatus(const QList<int> &items)
{

    foreach(auto input, inputs) {
        bool alarm=false;
        for(auto it=items.begin(); it!=items.end(); ++it) {
            if(*it==input->getInputID()) alarm=true;
        }
        input->setAlarm(alarm);
    }
    foreach(auto tinput, tinyInputs) {
        bool alarm=false;
        for(auto it=items.begin(); it!=items.end(); ++it) {
            if(*it==tinput->getID()) alarm=true;
        }
        tinput->setState(alarm);
    }
}

void MapWidget::clearLayout(QLayout *layoutt) {
    if (layoutt != nullptr )
    {
        QLayoutItem* item;
        while ( ( item = layoutt->takeAt( 0 ) ) != nullptr )
        {
            delete item->widget();
            delete item;
        }
    }
}
