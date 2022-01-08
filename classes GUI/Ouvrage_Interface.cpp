/**
 * \file Ouvrage_Interface.cpp
 * \brief Définition des méthodes d'ajout d'ouvrage
 * \author Guillaume Gagnon
 * \date 29 novembre 2021
 */

#include "Ouvrage_Interface.h"
#include "Ouvrage.h"
#include "Validations.h"
#include "QMessageBox"


Ouvrage_Interface::Ouvrage_Interface ()
{
  widget.setupUi (this);
}


Ouvrage_Interface::~Ouvrage_Interface () { }


QString
Ouvrage_Interface::reqAuteurs () const
{
  return widget.auteurs_ouvrage->text ();
}


QString
Ouvrage_Interface::reqTitre () const
{
  return widget.titre_ouvrage->text ();
}


int
Ouvrage_Interface::reqAnnee () const
{
  return widget.annee_ouvrage->value ();
}


QString
Ouvrage_Interface::reqIdentifiant () const
{
  return widget.id_ouvrage->text ();
}


QString
Ouvrage_Interface::reqEditeur () const
{
  return widget.editeur_ouvrage->text ();
}


QString
Ouvrage_Interface::reqVille () const
{
  return widget.ville_ouvrage->text ();
}


void
Ouvrage_Interface::valideEnregistrementOuvrage ()
{
  if (util::validerFormatNom ((reqAuteurs ()).toStdString ()) != true || reqAuteurs ().isEmpty () == true)
    {
      QString message ("Le nom de(s) l'auteur(s) doit etre valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTitre ().isEmpty ())
    {
      QString message ("Le titre doit etre non vide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqAnnee () <= 0)
    {
      QString message ("L'annee doit etre superieure a 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  std::string identifiant = reqIdentifiant ().toStdString (); // debut check id
  if (identifiant.length () != 22)
    {
      QString message ("L'identifiant doit etre valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (identifiant.length () == 22)
    {
      if (identifiant.find ("ISBN") != std::string::npos)
        {
          if (util::validerCodeIsbn (identifiant) != true)
            {
              QString message ("L'identifiant doit etre valide.");
              QMessageBox::information (this, "ERREUR", message);
              return;
            }
        }
    }                                                         // fin check id
  if (util::validerFormatNom ((reqEditeur ()).toStdString ()) != true || reqEditeur ().isEmpty () == true)
    {
      QString message ("L'editeur doit etre valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (util::validerFormatNom ((reqVille ()).toStdString ()) != true || reqVille ().isEmpty () == true)
    {
      QString message ("La ville doit etre valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}