/**
 * \file Journal.h
 * \brief Prototype de la classe Journal, classe derivee de la classe mere Reference
 * \author Guillaume Gagnon
 * \date 29 octobre 2021, 11:01
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"
#include "ContratException.h"

namespace biblio
{

  /**
   * \class Journal
   * \brief classe Journal permettant de modeliser des references bibliographiques de categorie journal. Herite de classe Reference
   * \author Guillaume Gagnon
   * \Date 29 octobre 2021
   */
  class Journal : public biblio::Reference
  {
  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
    void verifieInvariant () const;

  public:
    Journal (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant, const std::string p_nom,
             int p_volume, int p_numero, int p_page);

    virtual Reference* clone () const;

    std::string reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;

    virtual std::string reqReferenceFormate () const;
  };
}


#endif /* JOURNAL_H */

