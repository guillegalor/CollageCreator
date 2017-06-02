#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>
#include <vector>

using namespace std;

class Problema{
  public:
    // Carga un problema desde el fichero dado por argumento.
    // Devuelve true si ok, y false si error al cargarlo
    bool cargarDesdeFlujo(const char *nombreFichero);

    // Devuelve la matriz sobre la que aplicaremos el algoritmo de Branch&Bound
    vector<vector<int> > getMatrix();

    int filas();  // Numero de filas de la foto
    int columnas(); // Numero de columnas de la foto

    // Imprime el problema en formato legible
    void prettyPrint();

  private:
    vector<vector<int> > foto;  // Matriz de pixeles de la foto
    vector<int> fotos;  // Fotos que se van a usar para el mural
};

#endif // PROBLEMA_H
