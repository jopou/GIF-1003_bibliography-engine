/**
 * \file Confirmation_Interface.h
 * \brief Prototype de l'interface pour confirmer la suppression
 * \author Brice Cauchon
 * \date 3 décembre 2021
 */

#ifndef _CONFIRMATION_INTERFACE_H
#define _CONFIRMATION_INTERFACE_H

#include "ui_Confirmation_Interface.h"

class Confirmation_Interface : public QDialog
{
  Q_OBJECT
public:
  Confirmation_Interface ();
  virtual ~Confirmation_Interface ();

private:
  Ui::Confirmation_Interface widget;
};

#endif /* _CONFIRMATION_INTERFACE_H */
