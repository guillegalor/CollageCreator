#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>
#include <vector>

using namespace std;

class Problema{
  public:
    bool cargarDesdeFlujo(const char *nombreFichero); // Carga un problema
                                                    // desde el fichero dado por argumento.
                                                    // Devuelve true si ok, y false
                                                    // si error al cargarlo
    // Devuelve la matriz sobre la que aplicaremos el algoritmo de Brach&Bound
    std::vector<std::vector<int> > getMatrix();
    int filas();
    int columnas();

  protected:
    std::vector<std::vector<int> > foto;
    std::vector<int> fotos;





    private:
};

#endif // PROBLEMA_H
