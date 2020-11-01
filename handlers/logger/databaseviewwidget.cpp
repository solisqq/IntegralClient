#include "databaseviewwidget.h"
#include "ui_databaseviewwidget.h"

#include <QDateTime>
#include <QSqlQuery>

DatabaseViewWidget::DatabaseViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DatabaseViewWidget)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->lowDateTime->setDateTime(QDateTime::currentDateTime());
    ui->highDateTime->setDateTime(QDateTime::currentDateTime());
    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideNone);
}

DatabaseViewWidget::~DatabaseViewWidget()
{
    delete ui;
}

void DatabaseViewWidget::resizeEvent(QResizeEvent *event)
{
    resetColumnsSize();
    QWidget::resizeEvent(event);
}

void DatabaseViewWidget::findByDate(const QDateTime& low, const QDateTime& high) {
    readyToResize = true;
    this->ui->tableView->setModel(getModelByDate(low,high));
    resetColumnsSize();
}

void DatabaseViewWidget::resetColumnsSize()
{
    if(!readyToResize) return;
    ui->tableView->setColumnWidth(0, this->width()/12);
    ui->tableView->setColumnWidth(1, this->width()/6);
    ui->tableView->setColumnWidth(2, this->width()/3);
    ui->tableView->resizeRowsToContents();
}

void DatabaseViewWidget::fetchData(QSqlQueryModel *model) {
    readyToResize = true;
    this->ui->tableView->setModel(model);
    connect(this->ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    resetColumnsSize();
}

void DatabaseViewWidget::onTableClicked(const QModelIndex& index) {
    Q_UNUSED(index)
    //qDebug()<< index.row()
    /*QModelIndex licensePlate = this->ui->tableView->model()->index(index.row(), 1);
    QModelIndex licenseDate = this->ui->tableView->model()->index(index.row(), 2);
    QString lplate = ui->tableView->model()->data(licensePlate).toString();
    QString ldate = ui->tableView->model()->data(licenseDate).toString();*/
}
QSqlQueryModel* DatabaseViewWidget::getModelByDate(const QDateTime& low, const QDateTime& high) {
    QSqlQueryModel *toRet = new QSqlQueryModel();
    QSqlQuery qry;
    qry.exec("""select * from log WHERE date>='"""+low.toString("yyyy-MM-dd hh:mm:ss")+"""' AND date<='"""+high.toString("yyyy-MM-dd hh:mm:ss")+"""';""");
    toRet->setQuery(qry);
    return toRet;
}

void DatabaseViewWidget::showEvent(QShowEvent *event)
{
    ui->lowDateTime->setDateTime(QDateTime::fromSecsSinceEpoch(QDateTime::currentDateTime().toSecsSinceEpoch()-3600));
    ui->highDateTime->setDateTime(QDateTime::currentDateTime());
    QWidget::showEvent(event);
}

void DatabaseViewWidget::on_searchBtn_clicked()
{
    findByDate(ui->lowDateTime->dateTime(), ui->highDateTime->dateTime());
}
