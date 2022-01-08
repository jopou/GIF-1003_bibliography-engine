/**
 * \file Reference.h
 * \brief Prototype de la classe Reference
 * \author Guillaume Gagnon
 * \date 2 octobre 2021, 16:09
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include "ContratException.h"
#include "Validations.h"

namespace biblio
{

  /**
   * \class Reference
   * \brief classe Reference permettant de modeliser des references bibliographiques. Cette classe est implementee dans le namespace biblio
   * \author Guillaume Gagnon
   * \Date 2 octobre 2021
   */
  class Reference
  {
  protected:
    virtual void verifieInvariant () const;
    std::string m_auteurs; //attributs en protected pour pouvoir les utiliser dans les reqFormate des classe derives
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;

  public:
    Reference (const std::string p_auteurs, const std::string p_titre, const int p_annee, const std::string p_identifiant); //constructeur

    virtual
    ~Reference (); // destructeur

    virtual
    Reference* clone () const = 0; // clonage d'une reference: le clonage se fait en sauvegardant le pointeur d'un objet reference

    std::string reqAuteurs () const; // 4 accesseurs
    std::string reqTitre () const;
    int reqAnnee () const;
    std::string reqIdentifiant () const;

    virtual std::string reqReferenceFormate () const; //methode d'affichage

    void asgAnnee (const int p_annee); //1 mutateur

    friend bool operator== (const Reference& p_ref, const Reference& p_ref2); //surcharge de l'operateur ==
  };
}


#endif /* REFERENCE_H */

