/**
 * \file Validations.h
 * \brief Prototypes des fonctions de validation developpees dans le Tp1, implementees dans le namespace util
 * \author Guillaume Gagnon
 * \date 2 novembre 2021, 20:09
 */

#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <string>

namespace util
{
  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
}


#endif /* VALIDATIONS_H */

