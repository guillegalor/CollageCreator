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

    int filas();
    int columnas();

  private:
    vector<vector<int> > foto;
    vector<int> fotos;
};

#endif // PROBLEMA_H
