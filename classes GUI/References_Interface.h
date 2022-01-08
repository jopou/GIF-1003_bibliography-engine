/**
 * \file Reference_Interface.h
 * \brief Prototype de l'interface pour l'ajout de references
 * \author Guillaume Gagnon
 * \date 27 novembre 2021, 21:40
 */

#ifndef _REFERENCES_INTERFACE_H
#define _REFERENCES_INTERFACE_H

#include "ui_References_Interface.h"
#include "Reference.h"
#include "Bibliographie.h"
#include <string>

class References_Interface : public QMainWindow
{
  Q_OBJECT
public:
  References_Interface (QWidget *parent = 0); // pourquoi il faut cette modif???

  /*References_Interface ();*/ // methode initiale fournie par QT

  virtual ~References_Interface ();

  void ajouterOuvrage (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant,
                       const std::string p_editeur, const std::string p_ville);
  void ajouterJournal (const std::string p_auteurs, const std::string p_titre, int p_annee, const std::string p_identifiant,
                       const std::string p_nom, int p_volume, int p_numero, int p_page);

  std::string reqBiblioFormate ();
  biblio::Bibliographie bibliographie;

private slots:
  void dialogOuvrage ();
  void dialogJournal ();
  void dialogSupprimer ();

private:
  Ui::References_Interface widget;

};

#endif /* _REFERENCES_INTERFACE_H */
