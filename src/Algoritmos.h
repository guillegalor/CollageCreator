#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include "Problema.h"
#include "Solucion.h"
#include <vector>

using namespace std;

Solucion CollageBranchBound(Problema p);
void BBFunc(vector<vector<int> > matrix, int& filas_elim, vector<int>& columnas_elim, int& cota_sup, int& cota_inf, int& coste, Solucion& sol, Solucion& mejor_sol);
int ValorMin(vector<vector<int> > matrix, int filas_elim, vector<int> columas_elim);


#endif // ALGORITMOS_H_INCLUDED
