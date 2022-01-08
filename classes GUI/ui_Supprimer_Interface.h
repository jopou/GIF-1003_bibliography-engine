/********************************************************************************
** Form generated from reading UI file 'Supprimer_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_INTERFACE_H
#define UI_SUPPRIMER_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Supprimer_Interface
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *id_ref;

    void setupUi(QDialog *Supprimer_Interface)
    {
        if (Supprimer_Interface->objectName().isEmpty())
            Supprimer_Interface->setObjectName(QString::fromUtf8("Supprimer_Interface"));
        Supprimer_Interface->resize(400, 300);
        buttonBox = new QDialogButtonBox(Supprimer_Interface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Supprimer_Interface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 241, 41));
        id_ref = new QLineEdit(Supprimer_Interface);
        id_ref->setObjectName(QString::fromUtf8("id_ref"));
        id_ref->setGeometry(QRect(10, 80, 291, 21));

        retranslateUi(Supprimer_Interface);
        QObject::connect(buttonBox, SIGNAL(accepted()), Supprimer_Interface, SLOT(dialogConfirmation()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Supprimer_Interface, SLOT(reject()));

        QMetaObject::connectSlotsByName(Supprimer_Interface);
    } // setupUi

    void retranslateUi(QDialog *Supprimer_Interface)
    {
        Supprimer_Interface->setWindowTitle(QApplication::translate("Supprimer_Interface", "Supprimer_Interface", nullptr));
        label->setText(QApplication::translate("Supprimer_Interface", "Identifiant de la r\303\251f\303\251rence \303\240 supprimer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Supprimer_Interface: public Ui_Supprimer_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_INTERFACE_H
