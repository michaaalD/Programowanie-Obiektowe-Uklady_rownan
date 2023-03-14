#include "matrix.hh"
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cassert>
#include <limits>

//#define epsilon 1e-9

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */



Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */

Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */


Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}


void Matrix::transpose(){                           //transponowanie macierzy
    double temp[SIZE][SIZE];

    for(int i=0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            temp[i][j]= this->value[i][j];
        }
    }
    for(int i=0; i< SIZE; i++){
        for(int j=0; j < SIZE; j++){
            std::swap(this->value[j][i], temp[i][j]);
        }
    }
}


float Matrix::detGauss()const{                        //funkcja obliczajaca wyznacnzik macierzy metoda gaussa

    
    float det = 1;                                   //zmienna pomocnicza do sprawzdenie parzystosci operacji
    float temp[SIZE][SIZE];                          // pomocnicza tablica to macierzy tymczasowej

    for(int i=0; i < SIZE; i++){                     //kopiowanie macierzy do maceirzy tymczasowej
        for(int j = 0; j < SIZE; j++){
            temp[i][j] = this->operator()(i,j);      
        }
    }

    if(SIZE != 3)
    {
    for(int i = 0; i < SIZE; i++){
       
        if(abs(temp[i][i]) < std::numeric_limits<float>::epsilon()){       //sprawdzenie czy element [0][0] == 0
            
            for(int j = i+1; j < SIZE; j++){                               
                
                if(abs(temp[j][i]) > std::numeric_limits<float>::epsilon()){    //sprawdzamy czy element [1][0] > 0
                    
                    for(int l=j; l < SIZE; l++){                                // jezeli tak zamianiemy elementy z kolumny 0 i 1 miejscami
                        
                        float x = temp[i][l];
                        temp[i][l]=temp[j][l];
                        temp[j][l] = x;
                            }
                        det = det * (-1);                                       // sprawdzanie parzystosci operacji
                        break;
                        }
                       
                        if(j==SIZE){                                            //jak doszlismy do konca to determinant = 0
                            det = 0;
                        }
            }
        }

        
            
        for(int j= i+1; j < SIZE ; j++){                                        //jak [0][0] != 0
                
            if(abs(temp[j][i]) < std::numeric_limits<float>::epsilon()) continue;
                    
            float D = temp[j][i] / temp[i][i];
                    
            for(int m = i+1; m < SIZE; m++){
                temp[j][m] -= D * temp[i][m];
                }
                    
            }
            
    }
        for(int i=0; i < SIZE; i++){
                    det *= temp[i][i];  
                    std::cout << "temp[i][i] na diagonali " << temp[i][i]<< std::endl;                                       //uwzglednienie parzystosci przez pomnozenie
                }
    return det;  

    }

   else if(SIZE == 3)
   {
    double w1,w2,w3;
    w1 = ( (temp[1][1] * temp[2][2]) - (temp[2][1] * temp[1][2]));
    w2 = ( (temp[1][0] * temp[2][2]) - (temp[2][0] * temp[1][2]) );
    w3 = ( (temp[1][0] * temp[2][1]) - (temp[2][0] * temp[1][1]) );
    det = (temp[0][0] * w1) - (temp[0][1] * w2) + (temp[0][2] * w3);
    return det;
   }
   
}



void Matrix::column_swap(int which_clmn, Vector clmn)
{
   if(which_clmn >=0 && which_clmn < SIZE)               //zamiana wiersza(po transponowaniu) na wektor wyrazow wolnych
    std::swap(this->value[which_clmn], clmn);
}