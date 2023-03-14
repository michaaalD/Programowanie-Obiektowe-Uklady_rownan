#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>



class Matrix {

private:
    Vector value[SIZE];               // Wartosci macierzy
    float determinant;                      // Wartosc wyznacznika

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);           //Operator dodawania dwoch macierzy

    double  &operator () (unsigned int row, unsigned int column);       //indeksowanie maceirzy
    
    const double &operator () (unsigned int row, unsigned int column) const;

    float get_det()const {return determinant;};        //funkcje dostepowe dla wyznacznika

    float set_det() {return determinant;};

    void transpose();               //transponowanie macierzy

    float detGauss()const;          //funkcja obliczajaca wyznacznik metoda gaussa

    void column_swap(int which_clmn, Vector clmn);
};

std::istream &operator>>(std::istream &in, Matrix &mat);        //przeciazenie pobrania do macierzy

std::ostream &operator<<(std::ostream &out, Matrix const &mat); //przeciazenie wyswietlenia macierzy

   



