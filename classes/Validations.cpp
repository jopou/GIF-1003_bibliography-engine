/**
 * \file Validations.cpp
 * \brief Implementation d'un namespace util contenant les fonctions de validation du Tp1
 * \author Guillaume Gagnon
 * \date 2 novembre 2021, 20:11
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "Validations.h"
#include <array>

using namespace std;

namespace util
{


  bool
  validerFormatNom (const string& p_nom)
  {
    bool nomValide = true;
    string espace ("  "), tiret ("--"), espaceTiret (" -"), tiretEspace ("- ");
    if (p_nom.find (espace) != std::string::npos)
      {
        nomValide = false;
      }
    else if (p_nom.find (tiret) != std::string::npos)
      {
        nomValide = false;
      }
    else if (p_nom.find (espaceTiret) != std::string::npos)
      {
        nomValide = false;
      }
    else if (p_nom.find (tiretEspace) != std::string::npos)
      {
        nomValide = false;
      }

    else
      {
        for (auto element : p_nom)
          {
            if (isdigit (element))
              {
                nomValide = false;
                break;
              }
            else
              {
                nomValide = true;
              }
          }
      }

    return nomValide;
  }


  bool
  validerCodeIssn (const std::string & p_issn)
  {
    bool validation = true;
    if (p_issn.substr (0, 5) != "ISSN ") validation = false;
    if (validation == true)
      for (int i = 5; i < 14; i++)
        {
          if (i == 9 and p_issn[i] == '-');
          else if (!isdigit (p_issn[i]))
            {
              validation = false;
            }
        }
    if (validation == true)
      {
        int somme = 0;
        for (int j = 5; j < 13; j++)
          {
            if (j < 9) somme += (p_issn[j] - '0') * (13 - j);

            if (j > 9) somme += (p_issn[j] - '0') * (14 - j);
          }
        if ((somme + (p_issn[13] - '0')) % 11 != 0) validation = false;
      }
    return validation;
  }


  bool
  validerCodeIsbn (const string & p_isbn)
  {
    bool validation = true;
    std::array<std::string, 5> domaine;

    if (p_isbn.length () != 22) validation = false;
    if (validation == true)
      {
        if (p_isbn.substr (0, 5) != "ISBN ") validation = false;
      }
    std::istringstream codeStream (p_isbn.substr (5, p_isbn.length () - 5));
    std::string token;
    int i = 0;
    int sommeCle = 0;
    int comptSomme = 0;
    while (std::getline (codeStream, token, '-') and validation == true)
      {
        try
          {
            if ( i > 4) throw i;
            domaine[i] = token;
            if ( i < 4)
              {
                for (int j = 0; j < domaine[i].length (); j++) // Somme pour cle
                  {
                    if (comptSomme % 2 == 0)
                      {
                        sommeCle += domaine[i][j] - '0';
                      }
                    else
                      {
                        sommeCle += 3 * (domaine[i][j] - '0');
                      }
                    comptSomme++;
                  }
              }

          }
        catch (int i)
          {
            validation = false;
          }

        i++;

      }
    if (validation == true) //validation du prefixe
      {
        if (!(domaine[0] == "978" or domaine[0] == "979")) validation = false;
      }
    if (validation == true) //validation du domaine
      {
        int dom = std::stoi (domaine[1]);
        int longDom = domaine[1].length ();
        switch (longDom)
          {
            case 1:
              if (!((dom >= 0 and dom <= 5) or dom == 7)) validation = false;
              break;
            case 2:
              if (!(dom >= 80 and dom <= 94)) validation = false;
              break;
            case 3:
              if (!((dom >= 600 and dom <= 649) or (dom >= 950 and dom <= 989))) validation = false;
              break;
            case 4:
              if (!(dom >= 9900 and dom <= 9989)) validation = false;
              break;
            case 5:
              if (!(dom >= 99900 and dom <= 99999)) validation = false;
              break;
            default: validation = false;
          }

      }
    if (validation == true) //validation de la cle de controle
      {
        int cle = 10 - (sommeCle % 10);
        if (cle == 10) cle = 0;
        if (stoi (domaine[4]) != cle) validation = false;
      }
    return validation;
  }
}