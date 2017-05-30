#ifndef SOLUCION_H
#define SOLUCION_H

#include "Problema.h"


class Solucion
{
    public:
        Solucion(); // Construye una solución vacía, con coste 0 y sin aristas
        Solucion(const Solucion & s); // Constructor de copia

        ~Solucion(); // Destructor

        Solucion & operator=(const Solucion & s); // Operador de asignación

        /*
            Devuelve los nodos origen y destino de la arista en la posición "a"
            de la solución, o origen=-1 y destino=-1 en caso de que no exista
        */
        void getArista(int a, int &origen, int &destino);

        double getCoste(); // Devuelve el coste de la solución


        /*
            Evalúa la solución actual en el problema "p". Como resultado, se modifica
            el coste de la solución actual. El coste será -1 si hay error al evaluar.
        */
        void Evaluar(Problema p);


        /*
            Modifica la solución actual añadiendo una arista <origen, destino>
            En caso de que la arista ya exista, no se inserta.
            En caso de que la arista <destino, origen> ya exista, no se inserta.
        */
        void addArista(int origen, int destino);


        int getNumAristas(); // Devuelve el número de aristas en la solución

    private:

        /*
          La solución vendra reprensentada por un vector de tamaño N*M en el que
          cada elemento contendrá el indice de la foto asignada a dicho pixel y
          un entero que representará el coste de dicha asignación.
        */

        std::vector<int> asignacion;
        int coste;
};

#endif // SOLUCION_H
