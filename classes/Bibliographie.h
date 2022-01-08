/**
 * \file Bibliographie.h
 * \brief Prototype de la classe Bibliographie
 * \author Guillaume Gagnon
 * \date 13 novembre 2021, 21:08
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include <string>
#include <vector>
#include "Reference.h"

namespace biblio
{

  class Bibliographie
  {
  private:
    std::string m_nomBiblio;
    std::vector<biblio::Reference*> m_vReferences;
    std::vector<biblio::Reference*>::const_iterator iter;
    bool referenceEstDejaPresente (const Reference& p_reference);
    void verifieInvariant () const;

  public:
    Bibliographie (const std::string& p_nomBiblio);
    Bibliographie (Bibliographie& p_bibliographie);
    virtual
    ~Bibliographie ();

    Bibliographie& operator= (Bibliographie& vecteurPourcopie);

    std::string reqNomBiblio () const;
    std::string reqBibliographieFormate ();

    void ajouterReference (const Reference& p_nouvelleReference);
    void supprimerReference (const std::string& p_identifiant);
  };
}


#endif /* BIBLIOGRAPHIE_H */

