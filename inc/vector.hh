#pragma once

#include "size.hh"
#include <iostream>

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector operator + (const Vector &v);         //operator dodawania wektorow

    Vector operator - (const Vector &v);         //operator odejmowania wektorow

    Vector operator * (const double &tmp);       //operator mnozenia wektorow
 
    Vector operator / (const double &tmp);       //operator dzielenia wektorow

    const double &operator [] (int index) const;   //indeksowanie wektorow

    double &operator [] (int index);

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);


