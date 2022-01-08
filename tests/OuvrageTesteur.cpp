/**
 * \file OuvrageTesteur.cpp
 * \brief Fichier test de la classe Ouvrage
 * \author Brice Cauchon
 * \version 1.0
 * \date 23 novembre 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "ContratException.h"
#include "Ouvrage.h"

/**
 * \class OuvrageValide
 * \brief Fixture de Ouvrage, crée un Ouvrage a utiliser dans plusieurs tests
 */
class OuvrageValide : public ::testing::Test
{

public:
  biblio::Ouvrage f_monOuvrage;


  OuvrageValide () :
  f_monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011,
                "ISBN 978-0-387-77591-3", "Springer", "New York") { };
} ;

//*************************************************************************
// Test du Constructeur Ouvrage::Ouvrage (const std::string&p_auteurs, const std::string& p_titre,
//                                        int p_annee, const std::string& p_identifiant,
//                                        const std::string& p_editeur, const std::string& p_ville)
// Cas valides:
// ConstructeurOuvrage : Construire un objet Ouvrage valide
// Cas invalide:
// ConstructeurAuteursInv : Constructeur avec paramètre Auteurs invalide
// ConstructeurAnneeInv : Constructeur avec paramètre Annee invalide
// ConstructeurTitreInv : Constructeur avec paramètre Titre invalide
// ConstructeurIdentifiantInv : Constructeur avec paramètre Identifiant invalide
// ConstructeurEditeurInv : Constructeur avec paramètre Editeur invalide
// ConstructeurVilleInv : Constructeur avec paramètre Ville invalide
//*************************************************************************


TEST (Ouvrage, ConstructeurOuvrage)
{

  biblio::Ouvrage monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition",
                              2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  ASSERT_EQ ("Homayoon Beigi", monOuvrage.reqAuteurs ()) << "L'auteur est incorrect";
  ASSERT_EQ ("Fundamentals of Speaker Recognition", monOuvrage.reqTitre ()) << "Le titre est incorrect";
  ASSERT_EQ (2011, monOuvrage.reqAnnee ()) << "L'année est incorrect";
  ASSERT_EQ ("ISBN 978-0-387-77591-3", monOuvrage.reqIdentifiant ()) << "L'identifiant est incorrect";
}


TEST (Ouvrage, ConstructeurAuteursInv)
{
  ASSERT_THROW (biblio::Ouvrage monOuvrage ("H-  -  -H", "Fundamentals of Speaker Recognition",
                                            2011, "ISBN 978-0-387-77591-3", "Springer", "New York"),
                PreconditionException)
          << "Si le nom des auteurs n'est pas valide il doit y avoir une erreur";
}


TEST (Ouvrage, ConstructeurAnneeInv)
{
  ASSERT_THROW (biblio::Ouvrage monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition",
                                            -50, "ISBN 978-0-387-77591-3", "Springer", "New York"),
                PreconditionException)
          << "L'année doit être plus grande que 0 sinon ça renvoit une erreur";
}


TEST (Ouvrage, ConstructeurTitreInv)
{
  ASSERT_THROW (biblio::Ouvrage monOuvrage ("Homayoon Beigi", "",
                                            2011, "ISBN 978-0-387-77591-3", "Springer", "New York"),
                PreconditionException)
          << "S'il n'y a pas de titre, il doit y avoir une erreur";
}


TEST (Ouvrage, ConstructeurIdentifiantInv)
{
  ASSERT_THROW (biblio::Ouvrage monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition",
                                            2011, "ISSN 1937-4771", "Springer", "New York"),
                PreconditionException)
          << "Si le code est invalide il doit y avoir une erreur";
}



//*************************************************************************
// Test de l'accesseur const std::string& Ouvrage::reqEditeur() const
// Cas valides:
// AccesEditeur : Retourne la valeur de l'attribut éditeur
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (OuvrageValide, AccesEditeur)
{
  ASSERT_EQ ("Springer", f_monOuvrage.reqEditeur ())
          << "La valeur retournée pour m_Editeur n'est pas bonne";
}
//*************************************************************************
// Test de l'accesseur const std::string& Ouvrage::reqVille() const
// Cas valides:
// AccesVille : Retourne la valeur de l'attribut ville
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (OuvrageValide, AccesVille)
{
  ASSERT_EQ ("New York", f_monOuvrage.reqVille ())
          << "La valeur retournée pour m_Ville n'est pas bonne";
}

//*************************************************************************
// Test de l'accesseur std::string Ouvrage::reqReferenceFormate () const
// Cas valides:
// AccesRefFormate : Retourne les attributs de l'Ouvrage formatée
// Cas invalide:
// Aucun Identifié
//*************************************************************************


TEST_F (OuvrageValide, AccesRefFormate)
{
  ASSERT_EQ ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer,"
             " 2011. ISBN 978-0-387-77591-3.", f_monOuvrage.reqReferenceFormate ())
          << "L'Ouvrage retournée n'est pas bon ou est mal formaté";
}