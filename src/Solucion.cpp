#include "Solucion.h"

Solucion::Solucion(): asignacion(), coste(0) {}

int Solucion::getCoste() {
  return coste;
}

void Solucion::set(int pixel, int foto, int coste){
  asignacion[pixel] = foto;
  this->coste += coste;
}
