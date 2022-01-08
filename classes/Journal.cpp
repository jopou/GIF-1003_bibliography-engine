/**
 * \file Journal.cpp
 * \brief Implementation de la classe Journal qui herite de la classe Reference
 * \author Guillaume Gagnon
 * \date 29 octobre 2021, 11:27
 */

#include "Reference.h"
#include "Journal.h"
#include <iostream>
#include <sstream>



namespace biblio
{


  /**
   * \brief   Constructeur par defaut d'un objet "journal" qui est une reference bibliographique d'un journal
   * \param[in] p_auteurs, le ou les auteurs du journal a referencer
   * \param[in] p_titre, le titre complet de l'article du journal a referencer
   * \param[in] p_annee, l'annee du journal a referencer
   * \param[in] p_identifiant, le code ISSN ou ISBN du journal a referencer
   * \param[in] p_nom, le nom du journal
   * \param[in] p_volume, le volume du journal
   * \param[in] p_numero, le numero d'identification du journal
   * \param[in] p_page, la page dans laquelle commence l'article du journal a referencer
   * \param[in] p_ISSN, le code ISSN du journal
   * \return  Un objet journal cree par le constructeur
   */
  Journal::Journal (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant, const std::string p_nom,
                    int p_volume, int p_numero, int p_page)
  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {
    PRECONDITION (util::validerCodeIssn (p_identifiant) == true);
    PRECONDITION (p_nom != "");

    POSTCONDITION (reqNom () == p_nom);
    POSTCONDITION (reqVolume () == p_volume);
    POSTCONDITION (reqNumero () == p_numero)
    POSTCONDITION (reqPage () == p_page);

    INVARIANTS ();
  }


  /**
   * \brief   Createur d'un clone d'une reference de type ouvrage pour placer dans la bibliographie
   * \return  le clone d'un objet ouvrage
   */
  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  /**
   * \brief   Accesseur pour le nom du journal
   * \return  m_nom, L'attibut qui constitue le nom de l'objet journal (du journal dans lequel on y retrouve l'artcile reference)
   */
  std::string
  Journal::reqNom () const
  {
    return m_nom;
  }


  /**
   * \brief   Accesseur pour le volume du journal
   * \return  m_volume, L'attibut qui constitue le volume de l'objet journal (du journal dans lequel on y retrouve l'artcile reference)
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \brief   Accesseur pour le numero du journal
   * \return  m_numero, L'attibut qui constitue le numero de l'objet journal (du journal dans lequel on y retrouve l'artcile reference)
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \brief   Accesseur pour la page de l'article du journal
   * \return  m_page, L'attibut qui constitue la page de l'objet journal (la page dans laquelle on y retrouve l'artcile reference)
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \brief   Methode de formatage des informations du journal contenant l'article a referencer, formant la reference complete du journal
   * \return  os, chaine de caracteres representant la reference complete du journal
   */
  std::string
  Journal::reqReferenceFormate () const
  {
    std::ostringstream os;

    os << m_auteurs << ". " << m_titre << ". " << m_nom << ", vol. " << m_volume << ", no. " << m_numero << ", pp. " << m_page << ", " << m_annee <<
            ". " << m_identifiant << ".";
    return os.str ();
  }


  /**
   * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
   */
  void
  Journal::verifieInvariant () const
  {
    Reference::verifieInvariant ();
    INVARIANT (m_nom.empty () == false);
    INVARIANT (util::validerCodeIssn (m_identifiant) == true);
  }
}