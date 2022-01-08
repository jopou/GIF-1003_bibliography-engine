/**
 * \file Supprimer_Interface.h
 * \brief Prototype de l'interface pour la suppression d'une référence
 * \author Brice Cauchon
 * \date 2 décembre 2021
 */

#ifndef _SUPPRIMER_INTERFACE_H
#define _SUPPRIMER_INTERFACE_H

#include "ui_Supprimer_Interface.h"

class Supprimer_Interface : public QDialog
{
  Q_OBJECT
public:
  Supprimer_Interface ();
  virtual ~Supprimer_Interface ();
  QString
  reqIdentifiant () const;
private slots:
  void dialogConfirmation ();
private:
  Ui::Supprimer_Interface widget;

};

#endif /* _SUPPRIMER_INTERFACE_H */
