#!/bin/bash
cd build
make
./unit_tests
./main < /home/michal/Desktop/kpo-zad4/macierz_testowa.txt
