/**
 * \file Ouvrage_Interface.h
 * \brief Prototype de l'interface pour l'ajout d'Ouvrages
 * \author Guillaume Gagnon
 * \date 29 novembre 2021
 */

#ifndef _OUVRAGE_INTERFACE_H
#define _OUVRAGE_INTERFACE_H

#include "ui_Ouvrage_Interface.h"

class Ouvrage_Interface : public QDialog
{
  Q_OBJECT
public:
  Ouvrage_Interface ();
  virtual ~Ouvrage_Interface ();

  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqEditeur () const;
  QString reqVille () const;

private slots:
  void valideEnregistrementOuvrage ();

private:
  Ui::Ouvrage_Interface widget;
};

#endif /* _OUVRAGE_INTERFACE_H */
