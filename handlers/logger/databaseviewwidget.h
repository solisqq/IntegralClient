#ifndef DATABASEVIEWWIDGET_H
#define DATABASEVIEWWIDGET_H

#include <QSqlQueryModel>
#include <QWidget>

namespace Ui {
class DatabaseViewWidget;
}

class DatabaseViewWidget : public QWidget
{
    Q_OBJECT
    bool readyToResize =false;

public:
    explicit DatabaseViewWidget(QWidget *parent = nullptr);
    ~DatabaseViewWidget() override;
    virtual void resizeEvent(QResizeEvent *event) override;
    void resetColumnsSize();
    void fetchData(QSqlQueryModel *model);

public slots:
    void findByDate(const QDateTime &low, const QDateTime &high);

private:
    Ui::DatabaseViewWidget *ui;
    QSqlQueryModel *getModelByDate(const QDateTime &low, const QDateTime &high);
    void showEvent(QShowEvent *event) override;

private slots:
    void onTableClicked(const QModelIndex&);
    void on_searchBtn_clicked();
};

#endif // DATABASEVIEWWIDGET_H
