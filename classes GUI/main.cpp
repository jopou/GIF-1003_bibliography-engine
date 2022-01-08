/**
 * \file main.cpp
 * \brief Fichier principale pour lancer l'interface de gestion de références
 * \author Brice Cauchon
 * \date 26 novembre 2021
 */

#include <QApplication>
#include "References_Interface.h"


int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  References_Interface fenetrePrincipale;
  fenetrePrincipale.show ();

  return app.exec ();
}
