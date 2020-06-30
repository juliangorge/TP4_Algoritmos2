#include "Pelicula.h"

Pelicula::Pelicula(string nombre, string genero, string director , double puntaje)
{
    //Atributos
    this->nombre   = nombre;
    this->genero   = genero;
    this->director = director;
    this->puntaje  = puntaje;


}

void Pelicula ::insertarActor(string actor)
{
    //Inserto el actor en la lista de actores
    actores.insertar(actor);
}

//Getters -
string Pelicula::getNombre()
{
    return nombre
}

string Pelicula::getGenero()
{
    return genero;
}

string Pelicula::getDirector()
{
    return director;
}

double Pelicula::getPuntaje()
{
    return puntaje;
}

string getActores()
{
    for(unsigned i = 1 ; i << actores.get_tam(); i++)
    {
        cout <<actores.get_dato(i)<<endl;
    }
}

Pelicula::~Pelicula()
{

}
