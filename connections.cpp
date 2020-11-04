#include "connections.h"
#include "ui_connections.h"

ConnectionEditor *Connections::getEditor()
{
    return &editor;
}

Database& Connections::getDatabase()
{
    return database;
}

Connections::Connections(QWidget *parent) :
    QWidget(parent),
    editor(this),
    database(this),
    ui(new Ui::Connections)
{
    ui->setupUi(this);
    loadMap();

    prevSize = this->size();
    loadPoints();
}
void Connections::loadPoints() {
    QSqlQueryModel *model = database.getAllIntegrals();
    for(int i = 0; i < model->rowCount(); i++)
    {
        createPoint(
                    QPointF(model->record(i).value(3).toReal(), model->record(i).value(4).toReal()),
                    model->record(i).value(2).toString(),
                    model->record(i).value(1).toString(),
                    model->record(i).value(0).toInt(),
                    model->record(i).value(7).toString().split(","),
                    model->record(i).value(8).toString(),
                    model->record(i).value(6).toInt()
                    );
        delay();
    }
    delete model;
}

void Connections::createPoint(const QPointF &pos, const QString& ipAddress, const QString& name, int id, QStringList zonesList, const QString& pass, int bgId)
{
    auto *point = new PinPoint(this);
    point->getConnection().setDatabase(&database);
    if(id!=-1) { //Jeżeli punkt jest ładowany
        point->fillSetup(ipAddress,name);
        point->setPos(Converter::toDefault(QPoint(settings.mapResolution.get(), settings.mapResolution.get()), Converter::sizeToPoint(this->size()), pos));
        point->setId(id);
    } else { //Jeżeli punkt jest tworzony
        QPointF qpoint = Converter::toDefault(Converter::sizeToPoint(this->size()), QPoint(settings.mapResolution.get(), settings.mapResolution.get()), pos);
        point->setId(database.addIntegral(point->getText(), point->getIP().toString(), qpoint.x(), qpoint.y(), settings.defaultConnectionBackground.get(),point->getConnection().getZonesWidget().getZonesNames(), point->getConnection().getPassword()));
        point->setPos(pos);
        zonesList<<"";
    }
    point->getConnection().setBackgroundID(bgId);
    point->getConnection().setPassword(pass);
    point->getConnection().getZonesWidget().setupZones(zonesList);
    point->getConnection().getMapWidget().passDatabase(database, id);
    editor.getAdder().TurnOff();
    points.append(point);
    point->show();
    connect(point, &PinPoint::setupDeclared, &this->editor, &ConnectionEditor::setupPoint);
    connect(point, &PinPoint::removeMe, this, &Connections::removePoint);
    connect(point, &PinPoint::updateDatabase, this, &Connections::updatePointInDatabase);
}

void Connections::updatePointInDatabase(PinPoint& pinPoint) {
    database.updateIntegral(pinPoint.getId(), pinPoint.getText(), pinPoint.getIP().toString(), pinPoint.getConnection().getMapWidget().getBackgroundId(), pinPoint.getConnection().getZonesWidget().getZonesNames(), pinPoint.getConnection().getPassword());
}

void Connections::removePoint(PinPoint* toRemove) {
    database.removeIntegral(toRemove->getId());
    toRemove->setParent(nullptr);
    points.removeOne(toRemove);
    delete toRemove;
}

Connections::~Connections()
{
    delete ui;
}

void Connections::mousePressEvent(QMouseEvent *event)
{
    if(editor.getAdder().state) {
        createPoint(event->localPos());

    }
}

void Connections::enterEvent(QEvent *event)
{
    editor.getAdder().MouseOverEnter();
    QWidget::enterEvent(event);
}

void Connections::leaveEvent(QEvent *event)
{
    editor.getAdder().MouseOverLeave();
    QWidget::leaveEvent(event);
}

void Connections::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    foreach(PinPoint *point, points)
        point->setPos(Converter::toCurrent(this->size(),prevSize,point->getPos()));

    prevSize = this->size();
}

void Connections::loadMap()
{
    this->ui->contentWidget->setStyleSheet("#contentWidget {border-image: url(\""+settings.imgPath.get()+"\") 0 0 0 0 stretch stretch;}");
}
void Connections::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(187);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
