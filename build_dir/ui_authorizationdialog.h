/********************************************************************************
** Form generated from reading UI file 'authorizationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATIONDIALOG_H
#define UI_AUTHORIZATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorizationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AuthorizationDialog)
    {
        if (AuthorizationDialog->objectName().isEmpty())
            AuthorizationDialog->setObjectName(QString::fromUtf8("AuthorizationDialog"));
        AuthorizationDialog->resize(332, 143);
        AuthorizationDialog->setStyleSheet(QString::fromUtf8("\n"
"#widget_2 {\n"
"	background-color: rgb(45, 45, 45);\n"
"	border: 4px solid rgb(85, 150, 255);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: rgb(30, 30, 30);\n"
"	border: 1px solid rgb(85, 150, 255);\n"
"	color: rgb(85, 150, 255);\n"
"	padding: 4px 10px;\n"
"	font: 75 10pt \"Segoe UI\";\n"
"	font-weight: 500;\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(85, 150, 255);\n"
"	border: 1px solid rgb(30, 30, 30);\n"
"	font: 75 10pt \"Segoe UI\";\n"
"	color: rgb(30, 30, 30);\n"
"	border-radius:5px;\n"
"	font-weight: 500;\n"
"}\n"
"\n"
"QPushButton::disabled {\n"
"	color:rgb(30, 47, 103);\n"
"	background-color:rgb(85, 106, 132);\n"
"	border: 1px solid rgb(7, 23, 59);\n"
"	border-radius: 10px;\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit::disabled {\n"
"	background-color: rgb(181, 181, 181);\n"
"}\n"
"QLineEdit::enabled {\n"
"	font-size: 11px;\n"
"	padding: 5px 10px;\n"
"	border: 1px solid rgb(80, 80, 80);\n"
"	border-radius: 4px;\n"
"	background-color:  rgb(60,60,60);"
                        "\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"QLineEdit::hover {\n"
"	border: 1px solid rgb(120, 120, 120);\n"
"	border-radius: 4px;\n"
"	background-color:  rgb(80,80,80);\n"
"}\n"
"\n"
"QLineEdit::focus {\n"
"	border: 1px solid rgb(100, 100, 100);\n"
"	border-radius: 4px;\n"
"	background-color:  rgb(70,70,70);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AuthorizationDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(AuthorizationDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-radius: 10px;"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font-size:18px;\n"
"font-weight: 500;\n"
"color: rgb(181, 221, 255);"));

        verticalLayout_4->addWidget(label_2, 0, Qt::AlignHCenter);


        verticalLayout_2->addWidget(widget_4);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:500;\n"
"color: rgb(238, 238, 238);"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addWidget(widget);

        buttonBox = new QDialogButtonBox(widget_2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout_2->addWidget(buttonBox, 0, Qt::AlignHCenter);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout->addWidget(widget_3);


        retranslateUi(AuthorizationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AuthorizationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AuthorizationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AuthorizationDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthorizationDialog)
    {
        AuthorizationDialog->setWindowTitle(QCoreApplication::translate("AuthorizationDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("AuthorizationDialog", "AUTORYZACJA", nullptr));
        label->setText(QCoreApplication::translate("AuthorizationDialog", "Has\305\202o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorizationDialog: public Ui_AuthorizationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATIONDIALOG_H
