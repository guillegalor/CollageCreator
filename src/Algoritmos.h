#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include "Problema.h"
#include "Solucion.h"

Solucion CollageBranchBound(Problema p);
void BBFunc(std::vector<std::vector<int> > matrix,int& filas_elim, std::vector<int>& columnas_elim, int& cota_sup, int& cota_inf, Solucion& sol, Solucion& mejor_sol);
int ValorMin(std::vector<std::vector<int> > matrix, int filas_elim, std::vector<int> columas_elim);


#endif // ALGORITMOS_H_INCLUDED
