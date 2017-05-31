#include "Solucion.h"

Solucion::Solucion(int tam): asignacion(tam), coste(0) {}

int Solucion::getCoste() {
  return coste;
}

void Solucion::set(int pixel, int foto, int coste){
  asignacion[pixel] = foto;
  this->coste += coste;
}

int Solucion::getFoto(int i){
  return asignacion[i];
}
