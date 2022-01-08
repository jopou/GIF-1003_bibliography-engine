/**
 * \file Journal_Interface.h
 * \brief Prototype de l'interface pour l'ajout d'un journal
 * \author Brice Cauchon
 * \date 28 novembre 2021
 */

#ifndef _JOURNAL_INTERFACE_H
#define _JOURNAL_INTERFACE_H

#include "ui_Journal_Interface.h"
#include "References_Interface.h"

class Journal_Interface : public QDialog
{
  Q_OBJECT
public:
  Journal_Interface ();
  virtual ~Journal_Interface ();
  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqNom () const;
  int reqVolume () const;
  int reqNumero ()const;
  int reqPage ()const;

private slots:
  void ValideEnregistrementJournal ();

private:
  Ui::Journal_Interface widget;
};

#endif /* _JOURNAL_INTERFACE_H */
