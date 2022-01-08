/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ReferenceException.h
 * Author: etudiant
 *
 * Created on November 30, 2021, 8:22 p.m.
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \Class ReferenceException
 * \brief Classe mère permettant de gérer les exceptions sur les références
 */
class ReferenceException : public std::runtime_error
{
public:

  ReferenceException (const std::string& p_raison) : std::runtime_error (p_raison) { }
};

/**
 * \Class ReferenceDejaPresenteException
 * \brief Classe dérivée permettant de gérer les exceptions lorsque la référence à ajouter est déjà présente
 */
class ReferenceDejaPresenteException : public ReferenceException
{
public:

  ReferenceDejaPresenteException (const std::string& p_raison) : ReferenceException (p_raison) { }
};

/**
 * \Class ReferenceAbsenteException
 * \brief Classe dérivée permettant de gérer les exceptions lorsque la référence à supprimer n'existe pas
 */
class ReferenceAbsenteException : public ReferenceException
{
public:

  ReferenceAbsenteException (const std::string& p_raison) : ReferenceException (p_raison) { }
};

#endif /* REFERENCEEXCEPTION_H */

