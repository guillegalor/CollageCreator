#include "Problema.cpp"
#include "Solucion.cpp"
#include "Algoritmos.cpp"
#include <iostream>

using namespace std;

int main() {

    Problema prob;
    Solucion sol;

    if(!prob.cargarDesdeFlujo("Problema.dat"))
        cout << "El fichero no se puede abrir" << endl;

    cout << "PROBLEMA: " << endl;
    /* Hay que implementar como mostrar el pretty print
    prob.prettyPrint();
    */

    // Resolvemos con algoritmo nuestro algoritmo
    sol = CollageBranchBound(prob);

    /*
    Mostramos la solución
    */

   return 0;
}
