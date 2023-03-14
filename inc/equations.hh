#include <iostream>
#include "matrix.hh"
#include "vector.hh"


class linearEquation{    //klasa definiujaca uklad rownan

    Matrix equation_matrix; //macierz wspolczynnikow
    float main_det;         //wyznacznik glowny macierzy
    Vector mistake_vector;  //wektor bledu
    Vector free_vector;     //wektor wyrazow wolnych
    Vector det;             //wektor wyznacznikow 
    Vector solved;          //wektor rozwiazan

    public:
    
    void Solve();    //funkcja obliczajaca rozwiazania ukladu rownan
    void Cramer();   //funkcja obliczajaca wyznacnziki macierzy
    friend std::ostream &operator <<(std::ostream &str_out, const linearEquation &equation);
    friend std::istream &operator >>(std::istream &str_in, linearEquation &equation);
    Vector get_det()const{return det;};    
    void mistake();  // funkcja obliczajaca wektor bledow
    void Display();  //funkcja wyswietlajaca macierz,wyznaczniki, rozwiazanie itp.   
};  

//std::istream &operator >>(std::istream &str_in, linearEquation &equation);         //przeciazenie wczytania wyrazenia
//std::ostream &operator <<(std::ostream &str_out, const linearEquation &equation);  //przeciazenie wypisania wyrazenia