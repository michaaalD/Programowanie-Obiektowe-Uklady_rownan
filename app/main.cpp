// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "exampleConfig.h"
#include "matrix.hh"
#include "vector.hh"
#include "equations.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 *
 * EDIT: dodane kreowanie wektorow i macierzy 
 */

int main() {
  std::cout
      << "Project System of Linear Equations" 
      /* << "\n Based on C++ Boiler Plate ver."
      << PROJECT_VERSION_MAJOR // duże zmiany, najczęściej brak kompatybilności wstecz
      << "." << PROJECT_VERSION_MINOR // istotne zmiany
      << "." << PROJECT_VERSION_PATCH // naprawianie bugów
      << "." << PROJECT_VERSION_TWEAK // zmiany estetyczne itd. */
      << std::endl;
  // std::system("cat ../LICENSE");
  
  

std::ifstream Plik;                    //test wczytanie

linearEquation Rownanie;

std::cin >> Rownanie;

Plik.close();

std::cout << Rownanie << std::endl;

Rownanie.Solve();                      //rozwiazanie ukladu rownan

Rownanie.Display();                    //wypisanie rozwiazan

}
