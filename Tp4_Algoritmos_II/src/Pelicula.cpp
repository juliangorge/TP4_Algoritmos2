#include "Pelicula.h"

Pelicula::Pelicula(string nombre, string genero, string director)
{
    //Atributos
    this->nombre   = nombre;
    this->genero   = genero;
    this->director = director;


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
