#ifndef PELICULA_H
#define PELICULA_H

#include<string>

#include "Lista_Template.h"

class Pelicula
{
    //Atributos
    private:

        string nombre;
        string genero;
        string director;
        double puntaje;

        Lista<string*> actores;

        //POST: verifica si un actor es parte de una pelicula. Devueve true en caso afirmativo
        bool buscarActorEnPelicula(string* actor, Pelicula* pelicula);

    //Metodos
    public: 

        //Constructor
        //PRE: puntaje debe etar comprendido entre 0 y 10
        Pelicula(string nombre, string genero, string director, double puntaje);

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
        bool compararGenero(Pelicula* peliculaAComparar);

        // POST: devuelve el true si el director es el mismo
        bool compararDirector(Pelicula* peliculaAComparar);

        // POST: devuelve el true si las peliculas comparten al menos 1 actor
        bool compararActores(Pelicula* peliculaAComparar);

        // POST: devulve true si el atributo puntaje de esta pelicula es mayor a 7
        // o si las peliculas comparten g�nero y comparten o el director o alg�n actor
        bool recomendarPorComparacion(Pelicula* peliculaAComparar);

};

#endif // PELICULA_H