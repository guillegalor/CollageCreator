#include "Algoritmos.h"
#include <iostream>

using namespace std;

Solucion CollageBranchBound(Problema P){
  // Inicializamos la matriz sobre la que vamos a trabajar
  vector<vector<int> > matrix = P.getMatrix();
  // Al comienzo tenemos todas las filas y todas las columnas disponibles
  int filas_elim = 0;
  vector<int> columnas_elim;
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
bool In(vector<int> v, int n){
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
int ValorMin(vector<vector<int> > matrix, int filas_elim, vector<int> columnas_elim){
  vector<int> vmin(matrix.size(),260);   //Usamos 260 pues sabemos que cada elem de la matriz es el valor abs de la diferencia de dos elementos menores que 255
  int rta = 0;

  for (unsigned i = filas_elim; i < matrix.size(); i++){
    for (unsigned j = 0; j < matrix[i].size(); j++)
      if (!In(columnas_elim, j) && (matrix[i][j] < vmin[i]))
        vmin[i] = matrix[i][j];

    rta += vmin[i];
  }

  return rta;
}

void BBFunc(vector<vector<int> > matrix,int filas_elim, vector<int> columnas_elim, int& cota_sup, int& cota_inf, int& coste, Solucion sol, Solucion& mejor_sol){
  // Condiciones de parada
  if (coste >= cota_sup)
    exit(0);//algo que todavia no se lo que devolverd
  // Si las hemos tomado un elemento de cada fila
  else if (filas_elim >= matrix.size()) {
    cota_sup = coste;
    mejor_sol = sol;
  }
  else{
    // Recorremos todas las columnas para explorar el nivel filas_elim. No tenemos en cuenta
      // las columnas ya utilizadas
    int vmin;
    for (unsigned int j = 0; j < matrix[filas_elim].size(); j++) {
      if (!In(columnas_elim, j)) {
        //Creamos una copia de las columnas eliminadas añadiendo la actual
        vector<int> columnas_elim_j = vector<int>(columnas_elim);
        columnas_elim_j.push_back(j);
        //Calculamos el valor minimo aproximado
        vmin = ValorMin(matrix, filas_elim+1, columnas_elim_j);
        //Comprobamos si es un valor valido, y exploramos a partir de este nodo
        if (vmin < cota_sup) {
          //Sol ahora mismo lo estoy usando como si fuera un vector de tamaño N*M, en el que
            // en cada posicion guardo la foto que se le asigna al respectivo pixel
          sol.set(filas_elim,j);
          BBFunc(matrix, filas_elim+1, columnas_elim_j, cota_sup, cota_inf, coste, sol, mejor_sol);
        }
      }
    }
  }

}
