#include "Problema.cpp"
#include "Solucion.cpp"
#include "Algoritmos.cpp"
#include <iostream>

using namespace std;

int main() {

    Problema prob;
    Solucion sol(prob.filas() * prob.columnas());

    if(!prob.cargarDesdeFlujo("Problema.dat"))
        cout << "El fichero no se puede abrir" << endl;

    // Mostramos el problema
    cout << "\nPROBLEMA: " << endl;
    prob.prettyPrint();

    // Resolvemos el problema
    sol = CollageBranchBound(prob);

    // Mostramos la solucion
    cout << "\nSOLUCION: " << endl;
    cout << "Coste de la solucion: " << sol.getCoste() << endl;
    cout << "Indice de la foto asignada a cada bloque: " << endl;
    for(int i=0; i<prob.filas(); i++){
      for(int j=0; j<prob.columnas(); j++){
        cout << sol.getFoto(i*prob.columnas()+j) << " | ";
      }
      cout << endl;
    }
    cout << endl;

   return 0;
}
