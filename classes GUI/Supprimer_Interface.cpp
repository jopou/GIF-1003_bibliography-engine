/**
 * \file Supprimer_Interface.cpp
 * \brief Définition de l'interface pour la suppression de référence
 * \author Brice Cauchon
 * \date 2 décembre 2021
 */

#include "Supprimer_Interface.h"
#include "Confirmation_Interface.h"


/**
 * \brief Constructeur de l'interface qui permet de supprimer une référence
 */
Supprimer_Interface::Supprimer_Interface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de l'interface qui permet de supprimer une référence
 */
Supprimer_Interface::~Supprimer_Interface () { }


/**
 * \brief Accesseur à l'identifiant à supprimer
 * \return le QString de id_ref dans l'interface
 */
QString
Supprimer_Interface::reqIdentifiant () const
{
  return widget.id_ref->text ();
}


/**
 * \brief le dialogue qui permet de confirmer si l'on veut bien supprimer la référence
 */
void
Supprimer_Interface::dialogConfirmation ()
{
  Confirmation_Interface dialogC;
  if (dialogC.exec ())
    {
      accept ();
    }
}