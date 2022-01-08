/**
 * \file Ouvrage.cpp
 * \brief Implementation de la classe Ouvrage qui herite de la classe Reference
 * \author Guillaume Gagnon
 * \date 27 octobre 2021, 13:30
 */

#include "Ouvrage.h"
#include <iostream>
#include <sstream>



namespace biblio
{


  /**
   * \brief   Constructeur par defaut d'un objet "ouvrage" qui est une reference bibliographique d'un ouvrage
   * \param[in] p_auteurs, le ou les auteurs de l'ouvrage a referencer
   * \param[in] p_titre, le titre complet de l'ouvrage a referencer
   * \param[in] p_annee, l'annee de l'ouvrage a referencer
   * \param[in] p_identifiant, le code ISSN ou ISBN de l'ouvrage a referencer
   * \param[in] p_editeur, le nom de l'editeur de l'ouvrage
   * \param[in] p_ville, la ville d'edition de l'ouvrage
   * \param[in] p_ISBN, le code ISBN de l'ouvrage
   * \return  Un objet ouvrage cree par le constructeur
   */
  Ouvrage::Ouvrage (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant, const std::string p_editeur,
                    const std::string p_ville)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION (util::validerCodeIsbn (p_identifiant));

    POSTCONDITION (reqEditeur () == p_editeur);
    POSTCONDITION (reqVille () == p_ville);

    INVARIANTS ();
  }


  /**
   * \brief   Createur d'un clone d'une reference de type ouvrage pour placer dans la bibliographie
   * \return  le clone d'un objet ouvrage
   */
  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  }


  /**
   * \brief   Accesseur pour l'editeur
   * \return  m_editeur, L'attibut qui constitue l'editeur de l'objet ouvrage
   */
  std::string
  Ouvrage::reqEditeur ()const
  {
    return m_editeur;
  }


  /**
   * \brief   Accesseur pour la ville d'edition
   * \return  m_ville, L'attibut qui constitue la ville d'edition de l'objet ouvrage
   */
  std::string
  Ouvrage::reqVille ()const
  {
    return m_ville;
  }


  /**
   * \brief   Methode de formatage des informations de l'ouvrage formant la reference complete de l'ouvrage
   * \return  os, chaine de caracteres representant la reference complete de l'ouvrage
   */
  std::string
  Ouvrage::reqReferenceFormate () const
  {
    std::ostringstream os;

    os << m_auteurs << ". " << m_titre << ". " << m_ville << " : " << m_editeur << ", " << m_annee << ". " << m_identifiant << ".";
    return os.str ();
  }


  /**
   * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
   */
  void
  Ouvrage::verifieInvariant ()const
  {
    Reference::verifieInvariant ();
    INVARIANT (util::validerCodeIsbn (m_identifiant) == true);
  }
}