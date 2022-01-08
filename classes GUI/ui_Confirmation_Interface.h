/********************************************************************************
** Form generated from reading UI file 'Confirmation_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATION_INTERFACE_H
#define UI_CONFIRMATION_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Confirmation_Interface
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *Confirmation_Interface)
    {
        if (Confirmation_Interface->objectName().isEmpty())
            Confirmation_Interface->setObjectName(QString::fromUtf8("Confirmation_Interface"));
        Confirmation_Interface->resize(360, 207);
        buttonBox = new QDialogButtonBox(Confirmation_Interface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 110, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Confirmation_Interface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 291, 51));

        retranslateUi(Confirmation_Interface);
        QObject::connect(buttonBox, SIGNAL(accepted()), Confirmation_Interface, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Confirmation_Interface, SLOT(reject()));

        QMetaObject::connectSlotsByName(Confirmation_Interface);
    } // setupUi

    void retranslateUi(QDialog *Confirmation_Interface)
    {
        Confirmation_Interface->setWindowTitle(QApplication::translate("Confirmation_Interface", "Confirmation_Interface", nullptr));
        label->setText(QApplication::translate("Confirmation_Interface", "\303\212tes-vous sur de vouloir supprimer la r\303\251f\303\251rence?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Confirmation_Interface: public Ui_Confirmation_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATION_INTERFACE_H
