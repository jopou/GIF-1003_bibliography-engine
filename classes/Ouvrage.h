/**
 * \file Ouvrage.h
 * \brief Prototype de la classe Ouvrage, classe derivee de la classe mere Reference
 * \author Guillaume Gagnon
 * \date 27 octobre 2021, 13:11
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"
#include "ContratException.h"
#include "Validations.h"

namespace biblio
{

  /**
   * \class Ouvrage
   * \brief classe Ouvrage permettant de modeliser des references bibliographiques de categorie ouvrage. Herite de classe Reference
   * \author Guillaume Gagnon
   * \Date 27 octobre 2021
   */
  class Ouvrage : public biblio::Reference
  {
  private:
    std::string m_editeur;
    std::string m_ville;
    void verifieInvariant () const;

  public:
    Ouvrage (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant, const std::string p_editeur,
             const std::string p_ville);

    virtual Reference* clone () const;

    std::string reqEditeur ()const;
    std::string reqVille () const;

    virtual std::string reqReferenceFormate () const;
  };
}

#endif /* OUVRAGE_H */

