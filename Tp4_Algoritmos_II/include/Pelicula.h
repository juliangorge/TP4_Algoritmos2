#ifndef PELICULA_H
#define PELICULA_H

#include<string>

#include"Lista_Template.h"

class Pelicula
{
    private: //Atributos

        string nombre;
        string genero;
        string director;
        double puntaje;

        Lista<string> actores;

    public: //Metodos

        //Constructor
        Pelicula(string nombre, string genero, string director);

        //PRE: Lista de actores
        //POST: Inserta el actor a la lista
        void insertarActor(string actor);

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
        //POST: Devuelve todo los actores
        string getActores();

};

#endif // PELICULA_H
