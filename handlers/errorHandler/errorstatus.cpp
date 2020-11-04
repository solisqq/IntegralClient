#include "errordialog.h"
#include "errorstatus.h"
#include "ui_errorstatus.h"
#include <QDebug>
#include <QTextBrowser>

void ErrorStatus::setDatabase(Database& value)
{
    database = &value;
}

Database *ErrorStatus::getDatabase() const
{
    return database;
}

ErrorStatus::ErrorStatus(QWidget *parent) :
    QWidget(parent),
    MenuElement(":/icons/img/error.png", nullptr, "0"),
    ui(new Ui::ErrorStatus)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ErrorStatus::checkForErrors);
    timer->start(settings.ErrorHandlerTimeOut.get()*1000);
    Global::errorHandler = this;
    agregator = new ErrorAgregator(this);
    connect(agregator, &ErrorAgregator::errorsAccepted, this, &ErrorStatus::handleAgregatorAccept);
    ui->scrollArea->setWidgetResizable(true);

    ui->scrollWidget->setStyleSheet("QWidget#scrollWidget {background-color: #282828; border-left: 2px solid rgb(85,150,255);}");//40,40,40
    ui->scrollArea->setStyleSheet("QScrollArea { background-color: #282828; border: 0;}");//40,40,40
}

void ErrorStatus::checkForErrors() {
    if(database==nullptr) return;

    Global::Alarm::turnOff();
    clear(this->ui->horizontalLayout);
    updateErrors();
    QList<Error*> toShow;
    for(auto error: errors) {
        auto widget = new errorWidget(error, this->ui->contentWidget);
        if(error->showInBar) {
            this->ui->horizontalLayout->addWidget(widget);
        }
        if(!error->getClicked() && error->noticable) {
            if(settings.production.get()) Global::Alarm::turnOn();
            toShow.append(error);
        }
        /*if(error->noticable && !error->noticed) {}*/
    }
    agregator->updateErrors(toShow);
    if(errors.count()>0) getIcon()->setText("Błędy: "+QString::number(errors.count())); //Zmień liczbę w menu jeżeli wystąpiły błędy
    else getIcon()->setText("Brak błędów");
    this->ui->horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
}

void ErrorStatus::handleAgregatorAccept()
{
    for(auto error: errors) {
        if(!error->getClicked() && error->noticable) {
            error->setClicked();
            Global::logger->add(*error);
            error->dateAccepted = QDateTime::currentDateTime();
            database->updateSingleValueIn("active_errors", "clicked", "true", error->getDbID());
        }
    }
}

void ErrorStatus::clear ( QLayout* layout )
{
    QLayoutItem* item;
    while ( ( item = layout->takeAt( 0 ) ) != nullptr )
    {
        delete item->widget();
        delete item;
    }
    qDeleteAll(errors.begin(), errors.end());
    errors.clear();
    update();
}

void ErrorStatus::updateErrors()
{
    auto errorsQuery = database->getAllErrors();

    for(int i = 0; i < errorsQuery->rowCount(); i++)
    {
        errors.append(Error::fromSQL(errorsQuery->record(i)));
    }
}

QWidget *ErrorStatus::getView(){return this;}
ErrorStatus::~ErrorStatus(){delete timer;delete ui;}

