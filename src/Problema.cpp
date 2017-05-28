#include "Problema.h"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int Problema::filas(){
  return foto.size();
}


int Problema::columnas(){
  return foto[0].size();
}

std::vector<std::vector<int> > Problema::getMatrix(){
  std::vector<std::vector<int> > matrix(filas()*columnas(), vector<int>(fotos.size()));

  for(int i = 0; i < filas()*columnas(); i++){
    for (int j = 0; j < fotos.size(); j++) {
      matrix[i][j] = abs( foto[i/columnas()][i%columnas()] - fotos[j] );
    }
  }

  return matrix;
}

bool Problema::cargarDesdeFlujo(const char *nombreFichero) {

    /*
        Formato del fichero
        Línea 1: N M(número de filas y columnas de la foto)
        Líneas 2-N+1: N filas con M valores cada una entre 0-255
        Líneas N+2-K con c K >= N*M+N+1

        Ver ejemplo: Problema.dat
    */
    // Inicializar a problema vacío
      // Se hace solo por usar clases de la STL

    int N, M, Nfotos;
    ifstream fichero;

    fichero.open( nombreFichero );
    if ( !fichero )
        return false;

    fichero >> N;
    if (N<=0) {
        fichero.close();
        N= 0;
        return false;
    }

    fichero >> M;
    if (M<=0) {
        fichero.close();
        M= 0;
        return false;
    }

    // Reserva de la memoria para la foto de tamaño N*M
    foto = std::vector<std::vector<int> >(N, std::vector<int>(M));

    // Leemos cada pixel
    for (unsigned int i= 0; i<N; i++)
      for (unsigned int j = 0; j < M; j++)
        fichero >> foto[i][j];

    // Leemos el numero de fotos
    fichero >> Nfotos;
    if (Nfotos< N*M) {
        fichero.close();
        Nfotos= 0;
        return false;
    }

    // Reservamos espacio para las fotos
    fotos = std::vector<int>(Nfotos);

    // Leemos todas las fotos
    for (size_t i = 0; i < Nfotos; i++)
      fichero >> fotos[i];


    while (!fichero.eof()) {
      char a;
      fichero >> a;
    }

    fichero.close();

/*
    cout << "N= " << N << endl;
    for (unsigned int i= 0; i<N; i++)
        cout << "Plaza " << nombresPlazas[i] << endl;

    for (unsigned int i= 0; i<N; i++)
        for (unsigned int j= 0; j<N; j++)
            if (precioCalles[i][j] != -1) {
                cout << "i=" << i<< " j=" << j << " p=" <<precioCalles[i][j] << " ";
                cout << nombresCalles[i][j]<<endl;
            }
*/

    return true;
}
