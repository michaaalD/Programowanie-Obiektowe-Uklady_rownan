#include "equations.hh"
#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>


std::istream &operator >>(std::istream &str_in, linearEquation &equation){

    Matrix temp;

    for(int i = 0; i < SIZE; i++){                   //wczytanie macierzy
        for(int j = 0 ; j < SIZE; j++){
            str_in >> temp(i,j);
        }
    }

    temp.transpose();                                //transpozycja macierzy glownej, zeby pozniej zmaienic kolumne z wektorem wyrazow wolnych

    for(int  i = 0; i < SIZE; i++){                  //wczytanie wektora wyrazow wolnych
        str_in >> equation.free_vector[i];
    }
    equation.equation_matrix = temp;
    
    return str_in;
}

std::ostream &operator <<(std::ostream &str_out,  const linearEquation &equation){
    Matrix temp;
    temp = equation.equation_matrix;
    str_out << "Macierz pobrana po tranzpozycji" << std::endl;
    str_out << temp;
    str_out << "Wektor wyrazow wolnych" <<std::endl;
    str_out << equation.free_vector;

    return str_out;

}

void linearEquation::Cramer()
{
    for(int i = 0; i < SIZE; i++){
        Matrix temp = equation_matrix;           //pomocnicza macierz tymczasowa
        temp.column_swap(i,free_vector);         //zamiana poszczegolnych w wektorem wyrazow wolnych
        std::cout << temp << std::endl;          // wypisanie zmaienionej macierzy
        det[i] = temp.detGauss();                //wpisanie wyznacznikow macierzy do wektora z wyznacznikami
    }
    
}

void linearEquation::Solve(){

    this->Cramer();                              //rozwiazanie metoda cramera

    this->main_det = equation_matrix.detGauss(); 

    if(main_det != 0){
        for(int i = 0; i < SIZE; i++){
           
            solved[i]=det[i]/main_det;
        }
    }
    else{                                        //sprawdzenie czy wyznacznik != 0
        std::cout << "Glowny wyznacznik = 0, brak rozwiazan" << std::endl;
        exit(1);
    }
    
    this->mistake();                             //oblcizenie wektora bledow
}

void linearEquation::mistake(){
    Vector temp1 = equation_matrix*solved;
    Vector temp2 = temp1 - (this->free_vector);

    mistake_vector = temp2;
}


void linearEquation::Display(){

    std::cout << "Wyznacnzik glowny" << std::endl;
    std::cout << this->main_det << std::endl;

    std::cout << "Wektor wyznacznikow " << std::endl;
    std::cout << this->det << std::endl;

    std::cout << "Wektor bledu" << std::endl;
    std::cout << this->mistake_vector << std::endl;

    std::cout << "Wektor rozwiazan" << std::endl;
    std::cout << this->solved << std::endl;
}
