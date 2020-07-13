#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Archivo.h"

//Constantes de opciones
const int OPCION_VISTAS = 1;
const int OPCION_NO_VISTAS = 2;
const int OPCION_RECOMENDADAS = 3;
const int OPCION_SALIR = 0;

using namespace std;

//Clase Menu encargada del manejo de datos
class Menu
{
    private:
        Archivo listas;

    public:

        //Constructor
        Menu();

        //PRE:
        //POST: Carga los datos al archivo
        void cargarDatos();

        //PRE -
        //POST: Muestra la lista de recomendacion
        void mostrarRecomendacion();

        //PRE:
        //POST:Muestra las peliculas vistas
        void mostrarVistas();

        //PRE:
        //POST: Muestra las peliculas no vistas
        void mostrarNoVistas();

        //PRE: -
        //POST: Muestra por pantalla las opciones del Menu
        void mostrarOpciones();

        //Destructor
        ~Menu();

};

#endif // MENU_H
