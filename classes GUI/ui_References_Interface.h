/********************************************************************************
** Form generated from reading UI file 'References_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFERENCES_INTERFACE_H
#define UI_REFERENCES_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_References_Interface
{
public:
    QAction *actionQuitter;
    QAction *actionOuvrage;
    QAction *actionJournal;
    QAction *actionSupprimer_reference;
    QWidget *centralwidget;
    QTextBrowser *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_reference;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *References_Interface)
    {
        if (References_Interface->objectName().isEmpty())
            References_Interface->setObjectName(QString::fromUtf8("References_Interface"));
        References_Interface->resize(804, 564);
        actionQuitter = new QAction(References_Interface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionOuvrage = new QAction(References_Interface);
        actionOuvrage->setObjectName(QString::fromUtf8("actionOuvrage"));
        actionJournal = new QAction(References_Interface);
        actionJournal->setObjectName(QString::fromUtf8("actionJournal"));
        actionSupprimer_reference = new QAction(References_Interface);
        actionSupprimer_reference->setObjectName(QString::fromUtf8("actionSupprimer_reference"));
        centralwidget = new QWidget(References_Interface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextBrowser(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(10, 0, 781, 511));
        References_Interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(References_Interface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 804, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_reference = new QMenu(menuMenu);
        menuAjouter_reference->setObjectName(QString::fromUtf8("menuAjouter_reference"));
        References_Interface->setMenuBar(menubar);
        statusbar = new QStatusBar(References_Interface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        References_Interface->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_reference->menuAction());
        menuMenu->addAction(actionSupprimer_reference);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);
        menuAjouter_reference->addAction(actionOuvrage);
        menuAjouter_reference->addAction(actionJournal);

        retranslateUi(References_Interface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), References_Interface, SLOT(close()));
        QObject::connect(actionOuvrage, SIGNAL(triggered()), References_Interface, SLOT(dialogOuvrage()));
        QObject::connect(actionJournal, SIGNAL(triggered()), References_Interface, SLOT(dialogJournal()));
        QObject::connect(actionSupprimer_reference, SIGNAL(triggered()), References_Interface, SLOT(dialogSupprimer()));

        QMetaObject::connectSlotsByName(References_Interface);
    } // setupUi

    void retranslateUi(QMainWindow *References_Interface)
    {
        References_Interface->setWindowTitle(QApplication::translate("References_Interface", "References_Interface", nullptr));
        actionQuitter->setText(QApplication::translate("References_Interface", "Quitter", nullptr));
        actionOuvrage->setText(QApplication::translate("References_Interface", "Ouvrage", nullptr));
        actionJournal->setText(QApplication::translate("References_Interface", "Journal", nullptr));
        actionSupprimer_reference->setText(QApplication::translate("References_Interface", "Supprimer reference", nullptr));
        menuMenu->setTitle(QApplication::translate("References_Interface", "Menu", nullptr));
        menuAjouter_reference->setTitle(QApplication::translate("References_Interface", "Ajouter reference", nullptr));
    } // retranslateUi

};

namespace Ui {
    class References_Interface: public Ui_References_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFERENCES_INTERFACE_H
