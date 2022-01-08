/********************************************************************************
** Form generated from reading UI file 'Ouvrage_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRAGE_INTERFACE_H
#define UI_OUVRAGE_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Ouvrage_Interface
{
public:
    QLabel *label;
    QLineEdit *auteurs_ouvrage;
    QLabel *label_2;
    QLineEdit *titre_ouvrage;
    QSpinBox *annee_ouvrage;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *id_ouvrage;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *editeur_ouvrage;
    QLineEdit *ville_ouvrage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Ouvrage_Interface)
    {
        if (Ouvrage_Interface->objectName().isEmpty())
            Ouvrage_Interface->setObjectName(QString::fromUtf8("Ouvrage_Interface"));
        Ouvrage_Interface->resize(758, 551);
        label = new QLabel(Ouvrage_Interface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 58, 16));
        auteurs_ouvrage = new QLineEdit(Ouvrage_Interface);
        auteurs_ouvrage->setObjectName(QString::fromUtf8("auteurs_ouvrage"));
        auteurs_ouvrage->setGeometry(QRect(200, 50, 481, 28));
        label_2 = new QLabel(Ouvrage_Interface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 130, 58, 16));
        titre_ouvrage = new QLineEdit(Ouvrage_Interface);
        titre_ouvrage->setObjectName(QString::fromUtf8("titre_ouvrage"));
        titre_ouvrage->setGeometry(QRect(200, 120, 481, 28));
        annee_ouvrage = new QSpinBox(Ouvrage_Interface);
        annee_ouvrage->setObjectName(QString::fromUtf8("annee_ouvrage"));
        annee_ouvrage->setGeometry(QRect(200, 190, 81, 26));
        annee_ouvrage->setMaximum(2022);
        label_3 = new QLabel(Ouvrage_Interface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 200, 101, 16));
        label_4 = new QLabel(Ouvrage_Interface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 260, 71, 16));
        id_ouvrage = new QLineEdit(Ouvrage_Interface);
        id_ouvrage->setObjectName(QString::fromUtf8("id_ouvrage"));
        id_ouvrage->setGeometry(QRect(200, 250, 481, 28));
        label_5 = new QLabel(Ouvrage_Interface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 320, 58, 16));
        label_6 = new QLabel(Ouvrage_Interface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 380, 101, 16));
        editeur_ouvrage = new QLineEdit(Ouvrage_Interface);
        editeur_ouvrage->setObjectName(QString::fromUtf8("editeur_ouvrage"));
        editeur_ouvrage->setGeometry(QRect(200, 310, 481, 28));
        ville_ouvrage = new QLineEdit(Ouvrage_Interface);
        ville_ouvrage->setObjectName(QString::fromUtf8("ville_ouvrage"));
        ville_ouvrage->setGeometry(QRect(200, 370, 481, 28));
        buttonBox = new QDialogButtonBox(Ouvrage_Interface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 500, 176, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Ouvrage_Interface);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ouvrage_Interface, SLOT(valideEnregistrementOuvrage()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ouvrage_Interface, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ouvrage_Interface);
    } // setupUi

    void retranslateUi(QDialog *Ouvrage_Interface)
    {
        Ouvrage_Interface->setWindowTitle(QApplication::translate("Ouvrage_Interface", "Ouvrage_Interface", nullptr));
        label->setText(QApplication::translate("Ouvrage_Interface", "Auteurs:", nullptr));
        label_2->setText(QApplication::translate("Ouvrage_Interface", "Titre:", nullptr));
        label_3->setText(QApplication::translate("Ouvrage_Interface", "Ann\303\251e d'edition:", nullptr));
        label_4->setText(QApplication::translate("Ouvrage_Interface", "Code ISBN:", nullptr));
        label_5->setText(QApplication::translate("Ouvrage_Interface", "Editeur:", nullptr));
        label_6->setText(QApplication::translate("Ouvrage_Interface", "Ville d'edition:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ouvrage_Interface: public Ui_Ouvrage_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRAGE_INTERFACE_H
