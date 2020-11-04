#include "terminaldialog.h"
#include "ui_terminaldialog.h"

TerminalDialog::TerminalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TerminalDialog)
{
    ui->setupUi(this);
    ui->plainTextEdit->setMaximumBlockCount(50);
}

void TerminalDialog::updateTerminal(TerminalDialog::Source src, QByteArray &arr, QString adnotation)
{
    if(!this->isVisible()) {
        if(this->ui->plainTextEdit->toPlainText().count()>5) ui->plainTextEdit->setPlainText("");
        return;
    }
    QString converted = arr.toHex();
    for(int i=0; i<converted.length(); i+=2) {
        converted = converted.insert(i, " 0x");
        i+=3;
    }
    if(adnotation.count()>2) {
        adnotation = "&nbsp;&nbsp;("+adnotation+")";
    }
    if(src==Source::In)
        this->ui->plainTextEdit->appendHtml("&lt;&lt; <font color=\"#6575b6\">"+converted+"</font>"+adnotation);
    else
        this->ui->plainTextEdit->appendHtml("&gt;&gt; <font color=\"#b66591\">"+converted+"</font>"+adnotation);
}

TerminalDialog::~TerminalDialog()
{
    delete ui;
}
