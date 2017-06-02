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


vector<vector<int> > Problema::getMatrix(){
  vector<vector<int> > matrix(filas()*columnas(), vector<int>(fotos.size()));
  // La matriz contiene las diferencias entre el valor del pixel de la foto
  // y las distintas fotos que tenemos disponibles par el mural
  for(int i = 0; i < filas()*columnas(); i++){
    for (unsigned j = 0; j < fotos.size(); j++) {
      matrix[i][j] = abs(foto[i/columnas()][i%columnas()] - fotos[j]);
    }
  }

  return matrix;
}


bool Problema::cargarDesdeFlujo(const char *nombreFichero) {

    /*
        Formato del fichero
        Línea 1: N M (número de filas y columnas de la foto)
        Líneas 2,...,N+1: N filas con M valores cada una entre 0-255
        Línea N+2: Numero de fotos disponibles para el mural
        Líneas N+3,...,N+3+K, con K >= N*M: valores de las K fotos del mural

        Ver ejemplo: Problema.dat
    */

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
    foto = vector<vector<int> >(N, vector<int>(M));

    // Leemos cada pixel
    for (int i= 0; i<N; i++)
      for (int j = 0; j < M; j++)
        fichero >> foto[i][j];

    // Leemos el numero de fotos
    fichero >> Nfotos;
    if (Nfotos< N*M) {
        fichero.close();
        Nfotos= 0;
        return false;
    }

    // Reservamos espacio para las fotos
    fotos = vector<int>(Nfotos);

    // Leemos todas las fotos
    for (int i = 0; i < Nfotos; i++)
      fichero >> fotos[i];


    while (!fichero.eof()) {
      char a;
      fichero >> a;
    }

    fichero.close();

    return true;
}


void Problema::prettyPrint() {
  cout << "Tamaño de la foto: " << filas() << "x" << columnas() << " bloques" << endl;
  cout << "Foto: " << endl;
  cout << "--------------------" << endl;
  for(int i=0; i<filas(); i++){
    for(int j=0; j<columnas(); j++){
      cout << foto[i][j] << " | ";
    }
    cout << endl;
  }
  cout << "--------------------" << endl;

  cout << "\nNumero de fotos disponibles: " << fotos.size() << endl;
  for(unsigned i=0; i<fotos.size(); i++){
    cout << fotos[i] << " | ";
  }
  cout << endl;
}
