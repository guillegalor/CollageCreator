#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"
#include <vector>


class Solucion
{
    public:
        Solucion(int tam); // Construye una solución con coste 0 y tamaño tam

        /*
        Devuelve el coste actual de la solución (El coste no es un coste real, es
        el coste hasta el momento)
         */
        int getCoste();

        /*
        Almacena en el pixel el indice de la foto que ocuparía dicho lugar e
        incrementa el valor del coste actual

        Parámetros:
          -pixel: Pixel de la foto a rellenar ()
          -foto: Indice de la foto del vector de fotos que ocupa dicho pixel
          -coste: coste de insertar esa foto en dicho pixel
         */
        void set(int pixel, int foto, int coste);

        // Devuelve la foto que hay asignada en la posicion i
        int getFoto(int i);

    private:

        /*
        La solución vendra reprensentada por un vector de tamaño N*M en el que
        cada elemento contendrá el indice de la foto asignada a dicho pixel y
        un entero que representará el coste de dicha asignación.
        */
        vector<int> asignacion;
        int coste;
};

#endif // SOLUCION_H
