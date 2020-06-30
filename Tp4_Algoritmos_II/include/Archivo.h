#ifndef MENU_H
#define MENU_H

#include"Lista_Template.h"
#include"Pelicula.h"


//Clase Archivo encargada del manejo de archivo
class Archivo
{
    private:

        //Listas cuyo tipo de dato es un puntero a una pelicula.
        Lista<Pelicula*> listaVistas ;
        Lista<Pelicula*> listaNoVistas ;
        Lista<Pelicula*> listaRecomendados ;

    public:

        //Constructor

        Archivo();

        //PRE: Peliculas vistas y no vistas ya cargadas
        void armarRecomendada();

        //PRE: Recibe un archivo txt
        //POST: Carga las peliculas a las listas
        void cargarPeliculas();

        //Destructor
        ~Archivo();

};

#endif // MENU_H
