/********************************************************************************
** Form generated from reading UI file 'dbask.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBASK_H
#define UI_DBASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBAsk
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DBAsk)
    {
        if (DBAsk->objectName().isEmpty())
            DBAsk->setObjectName(QStringLiteral("DBAsk"));
        DBAsk->resize(401, 89);
        verticalLayout = new QVBoxLayout(DBAsk);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(DBAsk);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(DBAsk);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DBAsk);
        QObject::connect(buttonBox, SIGNAL(accepted()), DBAsk, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DBAsk, SLOT(reject()));

        QMetaObject::connectSlotsByName(DBAsk);
    } // setupUi

    void retranslateUi(QDialog *DBAsk)
    {
        DBAsk->setWindowTitle(QApplication::translate("DBAsk", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DBAsk", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBAsk: public Ui_DBAsk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBASK_H
