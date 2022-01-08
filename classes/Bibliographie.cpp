/**
 * \file Bibliographie.cpp
 * \brief Implementation de la classe Bibliographie
 * \author Guillaume Gagnon
 * \date 13 novembre 2021, 21:34
 */

#include "Bibliographie.h"
#include "ContratException.h"
#include "ReferenceException.h"
#include <vector>
#include <iostream>
#include <sstream>


namespace biblio
{


  /**
   * \brief   Constructeur par defaut d'un objet "bibliographie" qui est un ensemble de references
   * \param[in] p_nomBiblio, le nom de la bibliographie que l'on desire creer
   * \pre p_auteurs doit etre valide tel que precise dans la fonction de validation validerFormatNom, p_titre ne doit pas etre vide,
   *      p_annee doit etre strictement plus grand que 0, p_identifiant doit etre valide tel que precise dans les fonctions
   *      validerCodeIssn  et validerCodeIsbn selon si p_identifiant est un code ISSN ou ISBN
   * \post l'objet reference doit etre construit selon les informations passees en parametres au constructeur
   * \return  Un objet reference cree par le constructeur
   */
  Bibliographie::Bibliographie (const std::string& p_nomBiblio) : m_nomBiblio (p_nomBiblio)
  {
    PRECONDITION (p_nomBiblio.empty () == false);
    POSTCONDITION (reqNomBiblio () == p_nomBiblio);
    INVARIANTS ();
  }


  /**
   * \brief   Destructeur par defaut d'un objet "bibliographie" qui est un ensemble de references - Coplien
   */
  Bibliographie::~Bibliographie ()
  {
    for (iter = m_vReferences.begin (); iter != m_vReferences.end () ; iter++)
      {
        delete *(iter);
      }
    m_vReferences.clear ();
  }


  /**
   * \brief   Constructeur d'un vecteur de references qui copie les references d'un autre vecteur - Coplien
   * \param La bibliographie qui sera copié
   *
   */
  Bibliographie::Bibliographie ( Bibliographie & p_bibliographie) : m_nomBiblio (p_bibliographie.reqNomBiblio ()),  m_vReferences (std::vector <Reference*>(0))
  {

    for (p_bibliographie.iter = p_bibliographie.m_vReferences.begin (); p_bibliographie.iter != p_bibliographie.m_vReferences.end (); p_bibliographie.iter++)
      {
        ajouterReference (**(p_bibliographie.iter));
      }

    POSTCONDITION (m_nomBiblio == p_bibliographie.reqNomBiblio ());
    INVARIANTS ();
  }


  /**
   * \brief   Surcharge de l'operateur d'assignation qui permet a un vecteur donné de prendre toutes les references contenues dans un autre vecteur
   *          et de se les assigner - Coplien
   */
  Bibliographie&
          Bibliographie::operator = (Bibliographie& p_bibliographie)
  {
    if (this != &p_bibliographie)
      {
        m_vReferences = std::vector <Reference*>();
        for (p_bibliographie.iter = p_bibliographie.m_vReferences.begin (); p_bibliographie.iter != p_bibliographie.m_vReferences.end () ; p_bibliographie.iter++)
          {
            ajouterReference (**(p_bibliographie.iter));
          }
        m_nomBiblio = p_bibliographie.m_nomBiblio;
      }
    INVARIANTS ();
    return *this;
  }


  /**
   * \brief   Accesseur pour le nom d'une bibliographie
   * \return  m_nomBiblio, L'attibut qui constitue de(s) l'auteur(s) de l'objet reference
   */
  std::string
  Bibliographie::reqNomBiblio () const
  {
    return m_nomBiblio;
  }


  /**
   * \brief   Methode de formatage des informations d'une bibliographie
   * \return  os, chaine de caracteres representant une bibliographie complete
   */
  std::string
  Bibliographie::reqBibliographieFormate ()
  {
    std::ostringstream os;

    os << m_nomBiblio << "\n" << "===============================\n";
    for (iter = m_vReferences.begin (); iter != m_vReferences.end () ; iter++)
      {
        os << "[" << (iter - m_vReferences.begin ()) + 1 << "] " << (**iter).reqReferenceFormate ();
      }
    return os.str ();

  }


  /**
   * \brief   Methode permettant de savoir si une reference est deja comprise dans une bibliographie
   * \para une référence à vérifier si elle est présente
   * \return  true si la reference est deja presente, false sinon
   */
  bool
  Bibliographie::referenceEstDejaPresente (const Reference& p_reference)
  {
    bool dejaPresente = false;

    for (iter = m_vReferences.begin (); iter != m_vReferences.end () ; iter++)
      {
        if ((**iter).reqIdentifiant () == p_reference.reqIdentifiant ())
          {
            dejaPresente = true;
          }
      }

    return dejaPresente;
  }


  /**
   * \brief   Methode permettant d'ajouter une reference dans la bibliographie
   */
  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    if (referenceEstDejaPresente (p_nouvelleReference))
      {
        throw ReferenceDejaPresenteException ("Impossible d'ajouter une reference deja presente.");
      }
    else
      {
        m_vReferences.push_back (p_nouvelleReference.clone ());
      }
    INVARIANTS ();
  }


  /**
   * \brief   Methode permettant d'ajouter une reference dans la bibliographie
   * \param   identifiant de la référence à supprimer
   */
  void
  Bibliographie::supprimerReference (const std::string& p_identifiant)
  {
    PRECONDITION (util::validerCodeIsbn (p_identifiant) or util::validerCodeIssn (p_identifiant));
    bool trouve = false;

    for (iter = m_vReferences.begin (); iter != m_vReferences.end () and trouve == false ; iter++)
      {
        if ((*iter)->reqIdentifiant () == p_identifiant)
          {
            trouve = true;
            delete (*iter);
            m_vReferences.erase (iter);
          }
      }

    if (not trouve)
      {
        throw ReferenceAbsenteException ("Impossible de supprimer une reference absente de la bibliographie.");
      }
    //POSTCONDITION vérifier si c'est supprimer?
    INVARIANTS ();
  }


  /**
   * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
   */
  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (m_nomBiblio.empty () == false);
  }
}

