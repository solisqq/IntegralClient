#include "malfunctionwidget.h"
#include "ui_malfunctionwidget.h"

MalfunctionWidget::MalfunctionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MalfunctionWidget)
{
    ui->setupUi(this);
    addMalfunctions({"EMPTY","OUT1","OUT2","OUT3","OUT4","+KPD","+EX1/2","BATT","AC","DT1","DT2","DTM","RTC","no DTR", "no BATT", "ext. modem", "ext. model"});
    ui->contentLayout->itemAt(0)->widget()->hide();
}


void MalfunctionWidget::addMalfunctions(const std::initializer_list<QString>& list) {
    for(auto name : list) {
        ui->contentLayout->addWidget(new Malfunction(name,ui->contentWidget));
    }
}

void MalfunctionWidget::setStates(const QList<int>& list) {
    Malfunction* current=nullptr;
    bool wasSet = false;
    for(int i=0; i<ui->contentLayout->count(); i++) {
        current = getMalfunctionByID(i);
        wasSet=false;
        if(current==nullptr) return;
        for(auto id : list) {
            wasSet=(id==i);
            if(wasSet) break;
        }
        if(current->setState(wasSet))
            emit(malfunctionStateChanged(*current));
    }
}

Malfunction* MalfunctionWidget::getMalfunctionByID(int id) {
    if(id<ui->contentLayout->count() && ui->contentLayout->itemAt(id)->widget()!=nullptr) {
        return static_cast<Malfunction*>(ui->contentLayout->itemAt(id)->widget());
    } else return nullptr;
}

QList<Malfunction*> MalfunctionWidget::getMalfunctions() {
    QList<Malfunction*> malfs;
    for(int i=0; i<ui->contentLayout->count(); i++) {
        auto malf = static_cast<Malfunction*>(ui->contentLayout->itemAt(i)->widget());
        if(malf->getState()) malfs.append(malf);
    }
    return malfs;
}

MalfunctionWidget::~MalfunctionWidget()
{
    delete ui;
}
