/**
 * \file BibliographieTesteur.cpp
 * \brief Fichier test de la classe Bibliographie
 * \author Brice Cauchon
 * \version 1.0
 * \date 21 novembre 2021
 */
#include <stdlib.h>
#include <iostream>
#include "Bibliographie.h"
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Journal.h"
#include "Ouvrage.h"
#include "ReferenceException.h"

/**
 * \class BibliographieDeuxReferences
 * \brief Fixture de Bibliographie, crée une Bibliographie a utiliser dans plusieurs tests
 *        ainsi que un Ouvrage et un Journal qui permettent d'ajouter des références
 */
class BibliographieDeuxReferences : public ::testing::Test
{

public:
  biblio::Bibliographie f_maBibliographie;
  biblio::Ouvrage f_monOuvrage;
  biblio::Journal f_monJournal;


  BibliographieDeuxReferences () : f_maBibliographie ("Ma bibliographie"),
  f_monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011,
                "ISBN 978-0-387-77591-3", "Springer", "New York"),
  f_monJournal ("Maurice Richard", "Mon article", 2020,
                "ISSN 1937-4771", "Le Soleil", 4, 13, 40) { };


} ;

//*************************************************************************
// Test du Constructeur Bibliographie::Bibliographie (const std::string&)
// Cas valides:
// ConstructeurAvecNom : Bibliographie avec un nom
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST (Bibliographie, ConstructeurAvecNom)
{
  biblio::Bibliographie biblioConstruite ("Ma bibliographie");
  ASSERT_EQ ("Ma bibliographie", biblioConstruite.reqNomBiblio ()) << "Le nom ne concorde pas";
}


//*************************************************************************
// Test du constructeur copie Bibliographie::Bibliographie (const Bibliographie & p_bibliographie)
// Cas valides:
// ConstructeurCopie : Construire une Bibliographie à partir d'une autre.
// Cas invalide:
//   Aucun identifié
//*************************************************************************


TEST (Bibliographie, ConstructeurCopie)
{
  biblio::Bibliographie maBiblio ("Ma bibliographie");
  biblio::Journal monJournal ("Maurice Richard", "Mon article", 2020,
                              "ISSN 1937-4771", "Le Soleil", 4, 13, 40);
  maBiblio.ajouterReference (monJournal);
  biblio::Bibliographie biblio2 = maBiblio;
  ASSERT_EQ (maBiblio.reqBibliographieFormate (), biblio2.reqBibliographieFormate ())
          << "La biblio construite doit donner la même chose";
}

//*************************************************************************
// Test de l'opérateur d'assigniation Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
// Cas valides:
// Assigniation : Assigner les valeurs d'une Bibliographie à une autre.
// Cas invalide:
//   Aucun identifié
//*************************************************************************


TEST_F (BibliographieDeuxReferences, Assigniation)
{
  f_maBibliographie.ajouterReference (f_monJournal);
  biblio::Bibliographie biblio2 ("Ma deuxieme Biblio");
  biblio2 = f_maBibliographie;
  ASSERT_EQ (f_maBibliographie.reqBibliographieFormate (), biblio2.reqBibliographieFormate ())
          << "La biblio assignée doit donner la même chose";
  ///l'opérateur == n'a pas été défini
}

//*************************************************************************
// Test de l'accesseur au nom de la bibliographie const std::string& Bibliographie::reqNomBiblio () const
// Cas valides:
// AccesNomBiblio : Accède au nom défini de la bibliographie
// Cas invalide:
//   Aucun identifié
//*************************************************************************


TEST_F (BibliographieDeuxReferences, AccesNomBiblio)
{
  ASSERT_EQ ("Ma bibliographie", f_maBibliographie.reqNomBiblio ()) << "Ce n'est pas le bon nom";
}

//*************************************************************************
// Test de l'accesseur à la bibliographie formatée std::string Bibliographie::reqBibliographieFormate () const
// Cas valides:
// AccesseurBiblioFormate : Retourne un string représentant la bibliographie de manière formatée
// Cas invalide:
//   Aucun identifié
//*************************************************************************


TEST_F (BibliographieDeuxReferences, AccesseurBiblioFormate)
{

  ASSERT_EQ ("Ma bibliographie\n===============================\n", f_maBibliographie.reqBibliographieFormate ())
          << "Ne retourne pas la bonne chose lorsqu'il ne contient aucune Reference";
  f_maBibliographie.ajouterReference (f_monJournal);
  ASSERT_EQ ("Ma bibliographie\n===============================\n[1] "
             "Maurice Richard. Mon article. Le Soleil, vol. 4, no. 13, pp. 40, 2020."
             " ISSN 1937-4771.", f_maBibliographie.reqBibliographieFormate ())
          << "Ne retourne pas le bonne chose lorsqu'il contient 1 Reference";
}


//*************************************************************************
// Test de la méthode qui ajoute des références void Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
// Cas valides:
// AjoutDeReference : Ajoute une référence
// Cas invalide:
//  AjoutEnDouble : La référence ne sera pas ajouté, car elle est déjà présente
//*************************************************************************


TEST_F (BibliographieDeuxReferences, AjoutDeReference)
{
  f_maBibliographie.ajouterReference (f_monJournal);
  f_maBibliographie.ajouterReference (f_monOuvrage);
  ASSERT_EQ ("Ma bibliographie\n===============================\n[1] "
             "Maurice Richard. Mon article. Le Soleil, vol. 4, no. 13, pp. 40, 2020."
             " ISSN 1937-4771.[2] Homayoon Beigi. Fundamentals of Speaker"
             " Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.",
             f_maBibliographie.reqBibliographieFormate ())
          << "La biblio le contient pas les bonnes références.";
}


TEST_F (BibliographieDeuxReferences, AjoutEnDouble)
{
  f_maBibliographie.ajouterReference (f_monJournal);
  ASSERT_THROW (f_maBibliographie.ajouterReference (f_monJournal), ReferenceDejaPresenteException)
          << "La Reference a été ajouté en double dans la biblio alors qu'elle y existe déjà";
}

//*************************************************************************
// Test de la méthode qui ajoute des références void Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
// Cas valides:
// SuppressionDeReference : Supprime une référence
// Cas invalide:
// ReferenceInexistante : La référence ne sera pas ajouté, car elle est déjà présente
//*************************************************************************


TEST_F (BibliographieDeuxReferences, SuppressionDeReference)
{
  f_maBibliographie.ajouterReference (f_monJournal);
  biblio::Bibliographie mabiblio2 = f_maBibliographie;
  f_maBibliographie.ajouterReference (f_monOuvrage);
  f_maBibliographie.supprimerReference (f_monOuvrage.reqIdentifiant ());
  ASSERT_EQ (f_maBibliographie.reqBibliographieFormate (), mabiblio2.reqBibliographieFormate ())
          << "La référence n'a pas bien été suppression";
}


TEST_F (BibliographieDeuxReferences, ReferenceInexistante)
{
  f_maBibliographie.ajouterReference (f_monJournal);
  ASSERT_THROW (  f_maBibliographie.supprimerReference (f_monOuvrage.reqIdentifiant ()), ReferenceAbsenteException)
          << "La référence n'était pas dans la bibliographie ça aurait du throw une erreur";
}