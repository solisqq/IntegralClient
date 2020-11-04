#include "erroragregator.h"
#include "ui_erroragregator.h"

ErrorAgregator::ErrorAgregator(QWidget *parent) :
    QDialog(nullptr),
    ui(new Ui::ErrorAgregator)
{
    Q_UNUSED(parent)
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    if(settings.blink.get()) {
        blinkTimer.setInterval(510);
        connect(&blinkTimer, &QTimer::timeout, this, &ErrorAgregator::blinkWindow);
        blinkTimer.start();
    }
}

ErrorAgregator::~ErrorAgregator()
{
    delete ui;
}
void ErrorAgregator::updateErrors(QList<Error*>& error) {
    clearLay();
    if(error.count()<=0) {
        if(!isHidden()) this->hide();
        return;
    }
    if(isHidden()) this->show();
    for(auto err: error) {
        ui->contentLayout->addWidget(new errorWidget(err,this));
    }
}
void ErrorAgregator::clearLay() {
    QLayoutItem* item;
    while ( ( item = ui->contentLayout->takeAt( 0 ) ) != nullptr )
    {
        //Global::logger->add(*qobject_cast<errorWidget*>(item->widget())->error);
        delete item->widget();
        delete item;
    }

}
void ErrorAgregator::setVisible(bool visible)
{
    QDialog::setVisible(visible);
    if(!visible) {
        QLayoutItem* item;
        while ( ( item = ui->contentLayout->takeAt( 0 ) ) != nullptr )
        {
            emit(errorsAccepted());
            delete item->widget();
            delete item;
        }
    }
}

void ErrorAgregator::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    /*Q_UNUSED(event)
    QLayoutItem* item;
    while ( ( item = ui->contentLayout->takeAt( 0 ) ) != nullptr )
    {
        qobject_cast<errorWidget*>(item->widget())->error->clicked=true;
        delete item->widget();
        delete item;
    }*/
}
void ErrorAgregator::blinkWindow()
{
    if(currentColor.contains("rgb(155")) setBorderColor("rgb(42, 35, 81)");
    else setBorderColor("rgb(155,29,29)");
}

void ErrorAgregator::setBorderColor(const QString& clr) {
    currentColor = clr;
    this->setStyleSheet("#ErrorAgregator{"
                        "color:white;"
                        "background-color: rgb(24, 24, 24);"
                        "border: 30px solid "+clr+";"
                                                 "border-radius:5px;"
                                                 "}"
                                                 "#scrollArea {"
                                                 "background-color: rgb(24, 24, 24);"
                                                 "}");
}
