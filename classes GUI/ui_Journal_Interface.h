/********************************************************************************
** Form generated from reading UI file 'Journal_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNAL_INTERFACE_H
#define UI_JOURNAL_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Journal_Interface
{
public:
    QLabel *label;
    QLineEdit *auteurs_journal;
    QLabel *label_2;
    QLineEdit *titre_journal;
    QLabel *label_3;
    QSpinBox *annee_journal;
    QLabel *label_4;
    QLineEdit *id_journal;
    QLabel *label_5;
    QLineEdit *nom_journal;
    QLabel *label_6;
    QSpinBox *vol_journal;
    QLabel *label_7;
    QSpinBox *num_journal;
    QLabel *label_8;
    QSpinBox *page_journal;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Journal_Interface)
    {
        if (Journal_Interface->objectName().isEmpty())
            Journal_Interface->setObjectName(QString::fromUtf8("Journal_Interface"));
        Journal_Interface->resize(399, 367);
        label = new QLabel(Journal_Interface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 50, 16));
        auteurs_journal = new QLineEdit(Journal_Interface);
        auteurs_journal->setObjectName(QString::fromUtf8("auteurs_journal"));
        auteurs_journal->setGeometry(QRect(112, 9, 241, 28));
        label_2 = new QLabel(Journal_Interface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 49, 32, 16));
        titre_journal = new QLineEdit(Journal_Interface);
        titre_journal->setObjectName(QString::fromUtf8("titre_journal"));
        titre_journal->setGeometry(QRect(112, 49, 241, 28));
        label_3 = new QLabel(Journal_Interface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 97, 16));
        annee_journal = new QSpinBox(Journal_Interface);
        annee_journal->setObjectName(QString::fromUtf8("annee_journal"));
        annee_journal->setGeometry(QRect(110, 90, 81, 26));
        annee_journal->setMaximumSize(QSize(634, 26));
        label_4 = new QLabel(Journal_Interface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 68, 16));
        id_journal = new QLineEdit(Journal_Interface);
        id_journal->setObjectName(QString::fromUtf8("id_journal"));
        id_journal->setGeometry(QRect(112, 133, 241, 28));
        label_5 = new QLabel(Journal_Interface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 180, 94, 16));
        nom_journal = new QLineEdit(Journal_Interface);
        nom_journal->setObjectName(QString::fromUtf8("nom_journal"));
        nom_journal->setGeometry(QRect(112, 173, 241, 28));
        label_6 = new QLabel(Journal_Interface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 220, 49, 16));
        vol_journal = new QSpinBox(Journal_Interface);
        vol_journal->setObjectName(QString::fromUtf8("vol_journal"));
        vol_journal->setGeometry(QRect(112, 213, 61, 26));
        label_7 = new QLabel(Journal_Interface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 250, 52, 16));
        num_journal = new QSpinBox(Journal_Interface);
        num_journal->setObjectName(QString::fromUtf8("num_journal"));
        num_journal->setGeometry(QRect(112, 245, 61, 26));
        label_8 = new QLabel(Journal_Interface);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 280, 33, 16));
        page_journal = new QSpinBox(Journal_Interface);
        page_journal->setObjectName(QString::fromUtf8("page_journal"));
        page_journal->setGeometry(QRect(112, 277, 61, 26));
        buttonBox = new QDialogButtonBox(Journal_Interface);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 320, 176, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(auteurs_journal);
        label_2->setBuddy(titre_journal);
        label_3->setBuddy(annee_journal);
        label_4->setBuddy(id_journal);
        label_5->setBuddy(nom_journal);
        label_6->setBuddy(vol_journal);
        label_7->setBuddy(num_journal);
        label_8->setBuddy(page_journal);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(vol_journal, num_journal);
        QWidget::setTabOrder(num_journal, page_journal);

        retranslateUi(Journal_Interface);
        QObject::connect(buttonBox, SIGNAL(accepted()), Journal_Interface, SLOT(ValideEnregistrementJournal()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Journal_Interface, SLOT(reject()));

        QMetaObject::connectSlotsByName(Journal_Interface);
    } // setupUi

    void retranslateUi(QDialog *Journal_Interface)
    {
        Journal_Interface->setWindowTitle(QApplication::translate("Journal_Interface", "Journal_Interface", nullptr));
        label->setText(QApplication::translate("Journal_Interface", "Auteurs:", nullptr));
        label_2->setText(QApplication::translate("Journal_Interface", "Titre:", nullptr));
        label_3->setText(QApplication::translate("Journal_Interface", "Ann\303\251e d'\303\251dition:", nullptr));
        label_4->setText(QApplication::translate("Journal_Interface", "CODE ISSN:", nullptr));
        label_5->setText(QApplication::translate("Journal_Interface", "Nom du journal:", nullptr));
        label_6->setText(QApplication::translate("Journal_Interface", "Volume:", nullptr));
        label_7->setText(QApplication::translate("Journal_Interface", "Num\303\251ro:", nullptr));
        label_8->setText(QApplication::translate("Journal_Interface", "Page:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Journal_Interface: public Ui_Journal_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNAL_INTERFACE_H
