/********************************************************************************
** Form generated from reading UI file 'keydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYDIALOG_H
#define UI_KEYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *KeyDialog)
    {
        if (KeyDialog->objectName().isEmpty())
            KeyDialog->setObjectName(QStringLiteral("KeyDialog"));
        KeyDialog->resize(412, 152);
        verticalLayout = new QVBoxLayout(KeyDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(KeyDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font-size: 30px;"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(KeyDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QLatin1String("font-size: 25px;\n"
"padding: 10px 10px 10px 10px;"));

        verticalLayout->addWidget(lineEdit);

        buttonBox = new QDialogButtonBox(KeyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QStringLiteral("font-size: 20px;"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(KeyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), KeyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), KeyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(KeyDialog);
    } // setupUi

    void retranslateUi(QDialog *KeyDialog)
    {
        KeyDialog->setWindowTitle(QApplication::translate("KeyDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("KeyDialog", "Kod b\305\202\304\231du:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeyDialog: public Ui_KeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYDIALOG_H
