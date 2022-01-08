/**
 * \file ReferenceTesteur.cpp
 * \brief Fichier test de la classe Reference
 * \author Brice Cauchon
 * \version 1.0
 * \date 22 novembre 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Reference.h"

/**
 * \class ReferenceTest
 * \brief Classe dérivée de Reference identique à Reference, seulement utilisé pour
 *        tester la classe Reference qui est abstraite.
 */
class ReferenceTest : public biblio::Reference
{

public:


  ReferenceTest (const std::string&p_auteurs, const std::string& p_titre, int p_annee,
                 const std::string& p_identifiant) : biblio::Reference (p_auteurs, p_titre, p_annee, p_identifiant) { };


  virtual std::string
  reqReferenceFormate () const
  {
    return biblio::Reference::reqReferenceFormate ();
  };


  virtual Reference*
  clone () const
  {
    return new ReferenceTest (*this);
  };


  virtual void
  verifieInvariant () const
  {
    biblio::Reference::verifieInvariant ();
  };


  virtual
  ~ReferenceTest () { };
} ;

/**
 * \class ReferenceTestValide
 * \brief Fixture de ReferenceTest, crée une Reference a utiliser dans plusieurs tests
 */
class ReferenceTestValide : public ::testing::Test
{

public:
  ReferenceTest f_maReference;


  ReferenceTestValide () :
  f_maReference ("Marcel", "Le petit Chaperon Rouge", 2021, "ISSN 1937-4771") { };

} ;

//*************************************************************************
// Test du Constructeur Reference::Reference (const std::string& p_auteurs, const std::string& p_titre,
//                      int p_annee, const std::string& p_identifiant)
// Cas valides:
// ConstructeurReference : Construire une reference valide
// Cas invalide:
// ConstructeurAuteursInv : Constructeur avec paramètre Auteurs invalide
// ConstructeurAnneeInv : Constructeur avec paramètre Annee invalide
// ConstructeurTitreInv : Constructeur avec paramètre Titre invalide
// ConstructeurIdentifiantInv : Constructeur avec paramètre Identifiant invalide
//*************************************************************************


TEST (Reference, ConstructeurReference)
{

  ReferenceTest maReference ("Marcel", "Le petit Chaperon Rouge", 2021, "ISSN 1937-4771");
  ASSERT_EQ ("Marcel", maReference.reqAuteurs ())
          << "L'auteur est incorrect";
  ASSERT_EQ ("Le petit Chaperon Rouge", maReference.reqTitre ()) << "Le titre est incorrect";
  ASSERT_EQ (2021, maReference.reqAnnee ()) << "L'année est incorrect";
  ASSERT_EQ ("ISSN 1937-4771", maReference.reqIdentifiant ()) << "L'identifiant est incorrect";
}


TEST (Reference, ConstructeurAuteursInv)
{
  ASSERT_THROW (ReferenceTest maReference ("Marcél   ll--", "Le petit Chaperon Rouge", 2021,
                                           "ISSN 1937-4771"), PreconditionException)
          << "Si le nom des auteurs n'est pas valide il doit y avoir une erreur";
}


TEST (Reference, ConstructeurAnneeInv)
{
  ASSERT_THROW (ReferenceTest maReference ("Marcel", "Le petit Chaperon Rouge", -1,
                                           "ISSN 1937-4771"), PreconditionException)
          << "L'année doit être plus grande que 0 sinon ça renvoit une erreur";
}


TEST (Reference, ConstructeurTitreInv)
{
  ASSERT_THROW (ReferenceTest maReference ("Marcel", "", 2021,
                                           "ISSN 1937-4771"), PreconditionException)
          << "S'il n'y a pas de titre, il doit y avoir une erreur";
}


TEST (Reference, ConstructeurIdentifiantInv)
{
  ASSERT_THROW (ReferenceTest maReference ("Marcel", "Le petit Chaperon Rouge", 2021,
                                           "ISSN 1912-4771"), PreconditionException)
          << "Si le code est invalide il doit y avoir une erreur";
}

//*************************************************************************
// Test de l'assignateur année void Reference::asgAnnee (int p_annee)
// Cas valides:
// ModifierAnnee : Modifie l'année de la Reference
// Cas invalide:
// AnneeNegative : Retourne une erreur, car l'année n'est pas valide
//*************************************************************************


TEST_F (ReferenceTestValide, ModifierAnnee)
{

  f_maReference.asgAnnee (2000);
  ASSERT_EQ (2000, f_maReference.reqAnnee ())
          << "L'année n'a pas correctement été modifiée";
}


TEST_F (ReferenceTestValide, AnneeNegative)
{

  ASSERT_THROW (f_maReference.asgAnnee (-1010), PreconditionException) << "Ça doit retourner une erreur si l'année est négative";
  ASSERT_EQ (2021, f_maReference.reqAnnee ()) << "L'année a changé même si c'était invalide";
}

//*************************************************************************
// Test de l'accesseur const std::string& Reference::reqAuteurs () const
// Cas valides:
// AccesAuteurs : Retourne la valeur de l'attribut auteurs
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, AccesAuteurs)
{
  ASSERT_EQ ("Marcel", f_maReference.reqAuteurs ())
          << "La valeur retournée pour m_Auteurs n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur int Reference::reqAnnee () const
// Cas valides:
// AccesAnnee : Retourne la valeur de l'attribut année
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, AccesAnnee)
{
  ASSERT_EQ (2021, f_maReference.reqAnnee ())
          << "La valeur retournée pour m_Annee n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur const std::string& Reference::reqTitre () const
// Cas valides:
// AccesTitre : Retourne la valeur de l'attribut titre
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, AccesTitre)
{
  ASSERT_EQ ("Le petit Chaperon Rouge", f_maReference.reqTitre ())
          << "La valeur retournée pour m_Titre n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur const std::string& Reference::reqIdentifiant () const
// Cas valides:
// AccesIdentifiant : Retourne la valeur de l'attribut identifiant
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, AccesIdentifiant)
{
  ASSERT_EQ ("ISSN 1937-4771", f_maReference.reqIdentifiant ())
          << "La valeur retournée pour m_Identifiant n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur const std::string& Reference::reqReferenceFormate () const
// Cas valides:
// AccesRefFormate : Retourne les attributs de la Reference formatée
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, AccesRefFormate)
{
  ASSERT_EQ ("Marcel. Le petit Chaperon Rouge. ", f_maReference.reqReferenceFormate ())
          << "La Reference retournée n'est pas bonne ou est mal formatée";
}

//*************************************************************************
// Test de l'opérateur bool Reference::operator == (const Reference& p_reference) const
// Cas valides:
// ReferencesEgales : Retourne les attributs de la Reference formatée
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (ReferenceTestValide, ReferencesEgales)
{
  ReferenceTest reference2 ("Marcel", "Le petit Chaperon Rouge", 2021, "ISSN 1937-4771");
  ASSERT_EQ (reference2, f_maReference) << "Ils ont les mêmes valeurs ça devrait être égale";
  ASSERT_EQ (f_maReference, f_maReference) << "C'est la même Reference ça devrait être égale";
}