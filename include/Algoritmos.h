#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include "Problema.h"
#include "Solucion.h"
#include <vector>

using namespace std;

// Devuelve la solucion al problema p
Solucion CollageBranchBound(Problema p);

// Algoritmo Branch&Bound para resulver el problema
void BBFunc(vector<vector<int> > matrix, int fila_actual, vector<int> columnas_elim,
            int& cota_sup, int& cota_inf, Solucion sol, Solucion& mejor_sol);

// Devuelve la suma del minimo de cada fila de la matriz correspondiente
int ValorMin(vector<vector<int> > matrix, int filas_elim, vector<int> columas_elim);


#endif // ALGORITMOS_H_INCLUDED
