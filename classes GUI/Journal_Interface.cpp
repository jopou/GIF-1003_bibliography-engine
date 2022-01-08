/**
 * \file Journal_Interface.cpp
 * \brief Définition de l'interface du Journal pour ajouter un journal
 * \author Brice Cauchon
 * \date 28 novembre 2021
 */

#include "Journal_Interface.h"
#include "Journal.h"
#include "Validations.h"
#include "QMessageBox"


/**
 * \brief constructeur de l'interface pour créer une référence journal
 */
Journal_Interface::Journal_Interface ()
{
  widget.setupUi (this);
  widget.annee_journal->setMaximum (10000);
  widget.annee_journal->setValue (2021);
}


/**
 * \brief destructeur de l'interface de création d'un journal
 */
Journal_Interface::~Journal_Interface () { }


/**
 * \brief Accesseur à l'auteurs écrit par l'utilisateur dans l'interface
 * \return un QString qui représente le champ auteurs_journal
 */
QString
Journal_Interface::reqAuteurs () const
{
  return widget.auteurs_journal->text ();
}


/**
 * \brief Accesseur au titre écrit par l'utilisateur dans l'interface
 * \return un QString qui représente le champ titre_journal
 */
QString
Journal_Interface::reqTitre () const
{
  return widget.titre_journal->text ();
}


/**
 * \brief Accesseur à l'année d'édition écrit par l'utilisateur dans l'interface
 * \return un int qui représente le champ annee_journal
 */
int
Journal_Interface::reqAnnee () const
{
  return widget.annee_journal->value ();
}


/**
 * \brief Accesseur à l'identifiant écrit par l'utilisateur dans l'interface
 * \return un QString qui représente le champ id_journal
 */
QString
Journal_Interface::reqIdentifiant () const
{
  return widget.id_journal->text ();
}


/**
 * \brief Accesseur au nom écrit par l'utilisateur dans l'interface
 * \return un QString qui représente le champ nom_journal
 */
QString
Journal_Interface::reqNom () const
{
  return widget.nom_journal->text ();
}


/**
 * \brief Accesseur au volume du journal écrit par l'utilisateur dans l'interface
 * \return un int qui représente le champ vol_journal
 */
int
Journal_Interface::reqVolume () const
{
  return widget.vol_journal -> value ();
}


/**
 * \brief Accesseur au numéro du journal écrit par l'utilisateur dans l'interface
 * \return un int qui représente le champ num_journal
 */
int
Journal_Interface::reqNumero () const
{
  return widget.num_journal -> value ();
}


/**
 * \brief Accesseur à la page du journal écrit par l'utilisateur dans l'interface
 * \return un int qui représente le champ page_journal
 */
int
Journal_Interface::reqPage () const
{
  return widget.page_journal -> value ();
}


void
Journal_Interface::ValideEnregistrementJournal ()
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

  if (util::validerCodeIssn (identifiant) != true)
    {
      QString message ("L'identifiant doit etre valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;

    }                                                         // fin check id
  if (reqNom ().isEmpty ())
    {
      QString message ("Le nom du journal doit etre non vide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}