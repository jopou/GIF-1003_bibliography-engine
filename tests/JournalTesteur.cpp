/**
 * \file JournalTesteur.cpp
 * \brief Fichier test de la classe Journal
 * \author Brice Cauchon
 * \version 1.0
 * \date 23 novembre 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Journal.h"

/**
 * \class JournalValide
 * \brief Fixture de Journal, crée un Journal a utiliser dans plusieurs tests
 */
class JournalValide : public ::testing::Test
{

public:
  biblio::Journal f_monJournal;


  JournalValide () :
  f_monJournal ("Maurice Richard", "Mon article", 2020,
                "ISSN 1937-4771", "Le Soleil", 4, 13, 40) { };
} ;

//*************************************************************************
// Test du Constructeur Journal::Journal (const std::string& p_auteurs,
//                                        const std::string& p_titre, int p_annee,
//                                        const std::string& p_identifiant,
//                                        const std::string& p_nom, int p_volume,
//                                        int p_numero, int p_page)
// Cas valides:
// ConstructeurJournal : Construire un objet Journal valide
// Cas invalide:
// ConstructeurAuteursInv : Constructeur avec paramètre Auteurs invalide
// ConstructeurAnneeInv : Constructeur avec paramètre Annee invalide
// ConstructeurTitreInv : Constructeur avec paramètre Titre invalide
// ConstructeurIdentifiantInv : Constructeur avec paramètre Identifiant invalide
// ConstructeurNomInv : Constructeur avec paramètre Nom invalide
//*************************************************************************


TEST (Journal, ConstructeurJournal)
{

  biblio::Journal monJournal ("Maurice Richard", "Mon article", 2020,
                              "ISSN 1937-4771", "Le Soleil", 4, 13, 40);
  ASSERT_EQ ("Maurice Richard", monJournal.reqAuteurs ())
          << "L'auteur est incorrect";
  ASSERT_EQ ("Mon article", monJournal.reqTitre ()) << "Le titre est incorrect";
  ASSERT_EQ (2020, monJournal.reqAnnee ()) << "L'année est incorrect";
  ASSERT_EQ ("ISSN 1937-4771", monJournal.reqIdentifiant ()) << "L'identifiant est incorrect";
  ASSERT_EQ ("Le Soleil", monJournal.reqNom ()) << "Le nom du journal est incorrect";
  ASSERT_EQ (4, monJournal.reqVolume ()) << "Le numéro de volume est incorrect";
  ASSERT_EQ (13, monJournal.reqNumero ()) << "Le numéro est incorrect";
  ASSERT_EQ (40, monJournal.reqPage ()) << "Le numéro de page est incorrect";
}


TEST (Journal, ConstructeurAuteursInv)
{
  ASSERT_THROW (biblio::Journal monJournal (" -- ---", "Mon article", 2020,
                                            "ISSN 1937-4771", "Le Soleil", 4, 13, 40), PreconditionException)
          << "Si le nom des auteurs n'est pas valide il doit y avoir une erreur";
}


TEST (Journal, ConstructeurAnneeInv)
{
  ASSERT_THROW (biblio::Journal monJournal ("Maurice Richard", "Mon article", -20,
                                            "ISSN 1937-4771", "Le Soleil", 4, 13, 40), PreconditionException)
          << "L'année doit être plus grande que 0 sinon ça renvoit une erreur";
}


TEST (Journal, ConstructeurTitreInv)
{
  ASSERT_THROW (biblio::Journal monJournal ("Maurice Richard", "", 2020,
                                            "ISSN 1937-4771", "Le Soleil", 4, 13, 40), PreconditionException)
          << "S'il n'y a pas de titre, il doit y avoir une erreur";
}


TEST (Journal, ConstructeurIdentifiantInv)
{
  ASSERT_THROW (biblio::Journal monJournal ("Maurice Richard", "Mon article", 2020,
                                            "ISSN 1337-2000", "Le Soleil", 4, 13, 40), PreconditionException)
          << "Si le code est invalide il doit y avoir une erreur";
}


TEST (Journal, ConstructeurNomInv)
{
  ASSERT_THROW (biblio::Journal monJournal ("Maurice Richard", "Mon article", 2020,
                                            "ISSN 1937-4771", "", 4, 13, 40), PreconditionException)
          << "S'il n'y a pas de nom il doit y avoir une erreur";
}

//*************************************************************************
// Test de l'accesseur const std::string& Journal::reqNom() const
// Cas valides:
// AccesNom : Retourne la valeur de l'attribut nom du journal
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (JournalValide, AccesNom)
{
  ASSERT_EQ ("Le Soleil", f_monJournal.reqNom ())
          << "La valeur retournée pour m_Nom n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur int Journal::reqVolume () const
// Cas valides:
// AccesVolume : Retourne la valeur de l'attribut volume
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (JournalValide, AccesVolume)
{
  ASSERT_EQ (4, f_monJournal.reqVolume ())
          << "La valeur retournée pour m_Volume n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur int Journal::reqNumero () const
// Cas valides:
// AccesNumero : Retourne la valeur de l'attribut Numero
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (JournalValide, AccesNumero)
{
  ASSERT_EQ (13, f_monJournal.reqNumero ())
          << "La valeur retournée pour m_Numero n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur int Journal::reqPage () const
// Cas valides:
// AccesPage : Retourne la valeur de l'attribut Page
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (JournalValide, AccesPage)
{
  ASSERT_EQ (40, f_monJournal.reqPage ())
          << "La valeur retournée pour m_Page n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur std::string Journal::reqReferenceFormate () const
// Cas valides:
// AccesRefFormate : Retourne les attributs du Journal formatée
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (JournalValide, AccesRefFormate)
{
  ASSERT_EQ ("Maurice Richard. Mon article. Le Soleil, vol. 4, no. 13, pp. 40,"
             " 2020. ISSN 1937-4771.", f_monJournal.reqReferenceFormate ())
          << "Le Journal retournée n'est pas bon ou est mal formaté";
}
