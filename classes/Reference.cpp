/**
 * \file Reference.cpp
 * \brief Implementation de la classe Reference
 * \author Guillaume Gagnon
 * \date 2 octobre 2021, 16:09
 */

#include "Reference.h"
#include <iostream>
#include <sstream>


namespace biblio
{


  /**
   * \brief   Constructeur par defaut d'un objet "reference" qui est une reference bibliographique
   * \param[in] p_auteurs, le ou les auteurs du document a referencer
   * \param[in] p_titre, le titre complet du document a referencer
   * \param[in] p_annee, l'annee du document a referencer
   * \param[in] p_identifiant, le code ISSN ou ISBN du document a referencer
   * \pre p_auteurs doit etre valide tel que precise dans la fonction de validation validerFormatNom, p_titre ne doit pas etre vide,
   *      p_annee doit etre strictement plus grand que 0, p_identifiant doit etre valide tel que precise dans les fonctions
   *      validerCodeIssn  et validerCodeIsbn selon si p_identifiant est un code ISSN ou ISBN
   * \post l'objet reference doit etre construit selon les informations passees en parametres au constructeur
   * \return  Un objet reference cree par le constructeur
   */
  Reference::Reference (const std::string p_auteurs, const std::string p_titre, const int p_annee, const std::string p_identifiant) : m_auteurs (p_auteurs), m_titre   (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION (util::validerFormatNom (p_auteurs) == true );  //les donnees doivent etre valides avant de les inserer dans le constructeur
    PRECONDITION (p_titre.empty () == false);
    PRECONDITION (p_annee > 0);
    if (p_identifiant.find ("ISSN") != std::string::npos)
      {
        PRECONDITION (util::validerCodeIssn (p_identifiant) == true);
      }

    if (p_identifiant.find ("ISBN") != std::string::npos)
      {
        PRECONDITION (util::validerCodeIsbn (p_identifiant) == true);
      }

    POSTCONDITION (reqAuteurs () == p_auteurs);  //le constructeur a-t-il fait son travail? Les attributs de l'objet correspondent-ils
    POSTCONDITION (reqTitre () == p_titre);     //    a ce qu'on a passe au constructeur?
    POSTCONDITION (reqAnnee () == p_annee);
    POSTCONDITION (reqIdentifiant () == p_identifiant);

    INVARIANTS ();  // sert a lancer la methode verifieInvariant. verifieInvariant se sert de la macro INVARIANT pour verifier si l'objet nouvellement
  }                 //        creer par le constructeur est valide dans son ensemble.


  /**
   * \brief   Destructeur par defaut d'un objet "reference"
   */
  Reference::~Reference () { };


  /**
   * \brief   Accesseur pour l'auteur
   * \return  m_auteurs, L'attibut qui constitue le nom de(s) l'auteur(s) de l'objet reference
   */
  std::string
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief   Accesseur pour le titre du document
   * \return  m_titre, L'attibut qui constitue le titre de l'objet reference
   */
  std::string
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief   Accesseur pour l'annee de reference du document
   * \return  m_annee, L'attibut qui constitue l'annee d'edition de l'objet reference
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief   Accesseur pour l'identifiant (ISSN ou ISBN)
   * \return  m_identifiant, L'attibut qui constitue le code ISSN ou ISBN de l'objet reference
   */
  std::string
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief   Methode de formatage des informations de la reference formant la reference complete
   * \return  os, chaine de caracteres representant la reference complete
   */
  std::string
  Reference::reqReferenceFormate () const    // methode qui permet l'abstraction de la classe Reference, ainsi, les classes derives de
  {                                             //    la classe Reference doivent aussi faire preuve de son implementation
    std::ostringstream os;

    os << m_auteurs << ". " << m_titre << ". ";

    return os.str ();
  }


  /**
   * \brief   Mutateur pour l'annee de reference du document
   * \param[in] p_annee, annee de l'ouvrage qu'on decide de changer
   */
  void
  Reference::asgAnnee (const int p_annee)
  {
    PRECONDITION (p_annee > 0);
    m_annee = p_annee;
    POSTCONDITION (reqAnnee () == p_annee);
    INVARIANTS ();
  }


  /**
   * \brief   Methode de surcharge de l'operateur == afin d'effectuer une comparaison sur tous les attributs. La surcharge permet de comparer les                 attributs de deux objets. On compare deux objets de la classe Reference en se basant sur la comparaison tous leurs attributs.
   * \return  true, si tous les attributs de deux references sont les memes, sinon, false
   */
  bool operator == (const Reference& p_ref, const Reference& p_ref2)
  {
    return (p_ref.m_auteurs == p_ref2.m_auteurs &&
            p_ref.m_titre == p_ref2.m_titre &&
            p_ref.m_annee == p_ref2.m_annee &&
            p_ref.m_identifiant == p_ref2.m_identifiant);
  }


  /**
   * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
   */
  void
  Reference::verifieInvariant () const
  {
    INVARIANT (util::validerFormatNom (m_auteurs) == true && m_titre.empty () == false && m_annee > 0 &&
               (util::validerCodeIssn (m_identifiant) == true || util::validerCodeIsbn (m_identifiant) == true));
  }
}


