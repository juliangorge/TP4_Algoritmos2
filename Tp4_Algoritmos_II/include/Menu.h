#ifndef MENU_H
#define MENU_H

#include"Lista_Template.h"
#include"Pelicula.h"


//Clase Menu encargada del manejo de datos
class Menu
{
    private:

        //Listas cuyo tipo de dato es un puntero a una pelicula.
        Lista<Pelicula*> listaVistas ;
        Lista<Pelicula*> listaNoVistas ;
        Lista<Pelicula*> listaRecomendados ;

    public:

        //Constructor

        Menu();

        //PRE: Peliculas vistas y no vistas ya cargadas
        void armarRecomendada();

        //PRE:Recibe un archivo txt
        //POST:Carga las peliculas a las listas
        void cargarPeliculas();

        //PRE -
        //POST: Muestra la lista de recomendacion
        void mostrarRecomendacion();

        //PRE: -
        //POST: Muestra por pantalla las opciones del Menu
        void mostrarOpciones();

        //Destructor
        ~Menu();

};

#endif // MENU_H
