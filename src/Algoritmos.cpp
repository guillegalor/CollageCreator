#include "Algoritmos.h"
#include <iostream>

using namespace std;

Solucion CollageBranchBound(Problema P){
  // Inicializamos la matriz sobre la que vamos a trabajar
  vector<vector<int> > matrix = P.getMatrix();
  /*cout << endl;
  for(int i=0; i<matrix.size(); i++){
    for(int j=0; j<matrix[0].size(); j++){
      cout << matrix[i][j] << " | ";
    }
    cout << endl;
  }*/
  // Al comienzo tenemos todas las filas y todas las columnas disponibles
  int fila_actual = 0;
  vector<int> columnas_elim;
  /*
    Calculamos la cota superior inicial tomando elementos en diagonal desde el
    (0,0) que sabemos que es siempre valida por elegir una foto distinta
    para cada pixel
  */
  int cota_sup = 0;
  for (unsigned i = 0; i < matrix.size(); i++) {
    cota_sup += matrix[i][i];
  }
  //cout << endl << "Cota sup: " << cota_sup << endl;

  /*
    Para calcular la cota inf, usamos la funcion ValorMin que nos devuelve la
    suma del minimo de cada fila, por lo que no sabemos si la solución es valida
    o no pero si que es mínima
  */
  int cota_inf = ValorMin(matrix, fila_actual, columnas_elim);
  //cout << endl << "Cota inf: " << cota_inf << endl;

  Solucion mejor_sol(matrix.size());
  Solucion sol(matrix.size());

  BBFunc(matrix, fila_actual, columnas_elim, cota_sup, cota_inf, sol, mejor_sol);

  return mejor_sol;
}

/*
Devuelve si un entero está incluido en un array de enteros o no
*/
bool In(vector<int> v, int n){
  for (unsigned i = 0; i < v.size(); i++) {
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

void BBFunc(vector<vector<int> > matrix, int fila_actual, vector<int> columnas_elim,
            int& cota_sup, int& cota_inf, Solucion sol, Solucion& mejor_sol){
  // Condiciones de parada
  if (sol.getCoste() >= cota_sup)
    return;
  // Si hemos rellenado la foto entera, nos salimos de la iteración, y actualizamos la cota superior
  else if (fila_actual >= (int)matrix.size()) {
    cota_sup = sol.getCoste();
    mejor_sol = sol;
    return;
  }
  else{
    // Recorremos todas las columnas para explorar el nivel fila_actual. No tenemos en cuenta
      // las columnas ya utilizadas
    int vmin;
    for (unsigned j = 0; j < matrix[fila_actual].size(); j++) {
      if (!In(columnas_elim, j)) {
        //Creamos una copia de las columnas eliminadas añadiendo la actual
        vector<int> columnas_elim_j = columnas_elim;
        columnas_elim_j.push_back(j);
        //Calculamos el valor minimo aproximado
        vmin = ValorMin(matrix, fila_actual+1, columnas_elim_j);
        //Comprobamos si es un valor valido, y exploramos a partir de este nodo
        if (vmin < cota_sup) {
          sol.set(fila_actual, j, matrix[fila_actual][j]);
          BBFunc(matrix, fila_actual+1, columnas_elim_j, cota_sup, cota_inf, sol, mejor_sol);
        }
      }
    }
  }

}
