#ifndef PELICULA_H
#define PELICULA_H

#include<string>

#include "Lista_Template.h"

class Pelicula
{
    private: //Atributos

        string nombre;
        string genero;
        string director;
        double puntaje;

        Lista<string*> actores;

    public: //Metodos

        //Constructor
        //PRE: puntaje debe etar comprendido entre 0 y 10
        Pelicula(string nombre, string genero, string director,double puntaje);

        //PRE: Lista de actores
        //POST: Inserta el actor a la lista
        void insertarActor(string* actor);

        //PRE:
        //POS: Muestra los datos de la pelicula
        void mostrarPelicula();

        //PRE: -
        //POST: Devuelve el nombre de la pelicula
        string getNombre();

        //PRE: -
        //POST: Devuelve el genero de la pelicula
        string getGenero();

        //PRE: -
        //POST: Devuelve el director de la pelicula
        string getDirector();

        //PRE:
        //POST: Devuelve el puntaje
        double getPuntaje();

        //PRE: -
        //POST: Devuelve todos los actores
        void mostrarActores();

        // POST: devuelve true si es mayor o igual a 7
        bool verificarPuntaje();

        // POST: devuelve el true si el genero es el mismo
        bool compararGenero(Pelicula* paliculaAComparar);

        // POST: devuelve el true si el director es el mismo
        bool compararDirector(Pelicula* paliculaAComparar);

        // POST: devuelve el true si las peliculas comparten al menos 1 actor
        bool compararActores(Pelicula* paliculaAComparar);

        // POST: devulve true si el atributo puntaje de esta pelicula es mayor a 7
        // o si las peliculas comparten género y comparten o el director o algún actor
        bool recomendarPorComparacion(Pelicula* paliculaAComparar);

};

#endif // PELICULA_H
