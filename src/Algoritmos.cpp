#include "Algoritmos.h"
#include <iostream>

using namespace std;

Solucion CollageBranchBound(Problema P){
  // Inicializamos la matriz sobre la que vamos a trabajar
  std::vector<std::vector<int> > matrix = P.getMatrix();
  // Al comienzo tenemos todas las filas y todas las columnas disponibles
  int filas_elim = 0;
  std::vector<int> columnas_elim;
  /*
    Calculamos la cota superior inicial tomando elementos en diagonal desde el
    (0,0) que sabemos que es siempre valida por elegir una foto distinta
    para cada pixel
  */
  int cota_sup = 0;
  for (unsigned int i = 0; i < matrix.size(); i++) {
    cota_sup += matrix[i][i];
  }
  /*
    Para calcular la cota inf, usamos la funcion ValorMin que nos devuelve la
    suma del minimo de cada fila, por lo que no sabemos si la solución es valida
    o no pero si que es mínima
  */
  int cota_inf = ValorMin(matrix, filas_elim, columnas_elim);
  int coste = 0;
  Solucion mejor_sol;
  Solucion sol;

  BBFunc(matrix, filas_elim, columnas_elim, cota_sup, cota_inf, coste, sol, mejor_sol);

  return mejor_sol;
}

/*
Devuelve si un entero está incluido en un array de enteros o no
*/
bool In(std::vector<int> v, int n){
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == n) {
      return true;
    }
  }
  return false;
}

/*
Devuelve la suma del mínimo de cada fila de matrix, excluyendo las filas y columnas
eliminadas
*/
int ValorMin(std::vector<std::vector<int> > matrix, int filas_elim, std::vector<int> columnas_elim){
  std::vector<int> vmin(matrix.size(),260);   //Usamos 260 pues sabemos que cada elem de la matriz es el valor abs de la diferencia de dos elementos menores que 255
  int rta = 0;

  for (unsigned int i = 0; i < matrix.size(); i++)
    if (i >= filas_elim)
      for (unsigned int j = 0; j < matrix[i].size(); j++)
        if (!In(columnas_elim, j) && (matrix[i][j] < vmin[i]))
          vmin[i] = matrix[i][j];

  for (size_t i = 0; i < vmin.size(); i++) {
    rta += vmin[i];
  }

  return rta;
}

void BBFunc(std::vector<std::vector<int> > matrix,int& filas_elim, std::vector<int>& columnas_elim, int& cota_sup, int& cota_inf, int& coste, Solucion& sol, Solucion& mejor_sol){
  // Condiciones de parada
  if (coste >= cota_sup)
    exit(0);//algo que todavia no se lo que devolverd
  // Si las hemos tomado un elemento de cada fila
  else if (filas_elim >= matrix.size()) {
    cota_sup = coste;
    mejor_sol = sol;
  }
}
