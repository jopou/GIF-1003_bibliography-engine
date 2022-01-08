
/**
 * \file Reference_Interface.cpp
 * \brief Implementation de l'interface pour l'ajout de references
 * \author Guillaume Gagnon
 * \date 27 novembre 2021, 21:41
 */

#include <iostream>
#include <sstream>
#include "References_Interface.h"
#include "Ouvrage.h"
#include "Ouvrage_Interface.h"
#include "ReferenceException.h"
#include "Journal_Interface.h"
#include "Journal.h"
#include "Reference.h"
#include "Bibliographie.h"
#include "Supprimer_Interface.h"
#include <QMessageBox>


References_Interface::References_Interface (QWidget *parent) : QMainWindow (parent), bibliographie ("Mabiblio") //pourquoi il faut cette modif???
{
  widget.setupUi (this);
  widget.affichage->setText (reqBiblioFormate ().c_str ());
}


/*References_Interface::References_Interface ()   // methode initiale fournie par QT
{
  widget.setupUi (this);
}*/


References_Interface::~References_Interface ()
{
  bibliographie.~Bibliographie ();
}


void
References_Interface::ajouterOuvrage (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant, const std::string p_editeur, const std::string p_ville)
{
  try
    {
      biblio::Ouvrage ouvrage (p_auteurs, p_titre, p_annee, p_identifiant, p_editeur, p_ville);

      bibliographie.ajouterReference (ouvrage);
    }
  catch (ReferenceDejaPresenteException& e)
    {

      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


void
References_Interface::dialogOuvrage ()
{
  Ouvrage_Interface Ouvrage;
  if (Ouvrage.exec ())
    {


      std::istringstream ss ((Ouvrage.reqAuteurs ()).toStdString ());
      std::string premierNomOuvrage;
      getline (ss, premierNomOuvrage, ',');

      ajouterOuvrage (premierNomOuvrage,
                      Ouvrage.reqTitre ().toStdString (),
                      Ouvrage.reqAnnee (),
                      Ouvrage.reqIdentifiant ().toStdString (),
                      Ouvrage.reqEditeur ().toStdString (),
                      Ouvrage.reqVille ().toStdString ());
    }
  widget.affichage->setText (reqBiblioFormate ().c_str ());
}


std::string
References_Interface::reqBiblioFormate ()
{
  return bibliographie.reqBibliographieFormate ();
}


void
References_Interface::dialogJournal ()
{
  Journal_Interface dialogJ;
  if (dialogJ.exec ())
    {
      biblio::Journal monJournal (dialogJ.reqAuteurs ().toStdString (),
                                  dialogJ.reqTitre ().toStdString (),
                                  dialogJ.reqAnnee (),
                                  dialogJ.reqIdentifiant ().toStdString (),
                                  dialogJ.reqNom ().toStdString (),
                                  dialogJ.reqVolume (),
                                  dialogJ.reqNumero (),
                                  dialogJ.reqPage ());
      try
        {

          bibliographie.ajouterReference (monJournal);
        }
      catch (ReferenceDejaPresenteException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
        }
    }
  widget.affichage->setText (reqBiblioFormate ().c_str ());
}


void
References_Interface::dialogSupprimer ()
{
  Supprimer_Interface dialogS;
  if (dialogS.exec ())
    {
      try
        {
          bibliographie.supprimerReference (dialogS.reqIdentifiant ().toStdString ());
        }
      catch (ReferenceAbsenteException& e)
        {
          QString message = (e.what ());
          QMessageBox::information (this, "ERREUR", message);
        }
    }
  widget.affichage->setText (reqBiblioFormate ().c_str ());
}