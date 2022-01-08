/**
 * \file Confirmation_Interface.cpp
 * \brief Définition de l'interface de confirmation pour confirmer la suppression
 * \author Brice Cauchon
 * \date 3 décembre 2021
 */

#include "Confirmation_Interface.h"


/**
 * \brief Constructeur de l'interface qui permet de confirmer ou non la suppression d'une référence
 */
Confirmation_Interface::Confirmation_Interface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de l'interface qui permet de confirmer ou non la suppression d'une référence
 */
Confirmation_Interface::~Confirmation_Interface () { }
