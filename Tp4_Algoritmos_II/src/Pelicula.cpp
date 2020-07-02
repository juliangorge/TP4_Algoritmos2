#include "Pelicula.h"


Pelicula::Pelicula(string nombre, string genero, string director , double puntaje)
{
    //Atributos
    this->nombre   = nombre;
    this->genero   = genero;
    this->director = director;
    this->puntaje  = puntaje;


}

void Pelicula ::insertarActor(string* actor)
{
    //Inserto el actor en la lista de actores
    actores.insertar(actor);
}

//Getters -
string Pelicula::getNombre()
{
    return nombre;
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

string Pelicula::getActores()
{
	Iterador<string*> iteradorActores;
	string* aux;
    for(actores.iniciar_iterador(iteradorActores); !iteradorActores.finalIterador(); iteradorActores.siguiente())
    {
    	aux = iteradorActores.obtenerDato();
        cout <<*aux<<endl;
    }
}


void Pelicula::mostrarPelicula()
{
    //Muestra las peliculas
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Director: "<<getDirector()<<endl;
    cout<<"Puntaje: "<<getPuntaje()<<endl;
    cout<<"Actores: \n"<<getActores()<<endl;
}

Pelicula::~Pelicula()
{

}

bool Pelicula::verificarPuntaje()
{
	return puntaje >= 7;
}

bool Pelicula::compararGenero(Pelicula* paliculaAComparar)
{
	return genero == paliculaAComparar->genero;
}

bool Pelicula::compararDirector(Pelicula* paliculaAComparar)
{
	return director == paliculaAComparar->director;
}

bool Pelicula::compararActores(Pelicula* paliculaAComparar)
{
	Iterador<string*> estaPelicula;
	Iterador<string*> otraPelicula;
	string* actorEstaPelicula;
	string* actorOtraPelicula;
	for(actores.iniciar_iterador(estaPelicula);!estaPelicula.finalIterador(); estaPelicula.siguiente())
	{
		actorEstaPelicula = estaPelicula.obtenerDato();
		for(paliculaAComparar->actores.iniciar_iterador(otraPelicula);!otraPelicula.finalIterador(); otraPelicula.siguiente())
		{
			actorOtraPelicula = otraPelicula.obtenerDato();
			if(*actorEstaPelicula == *actorOtraPelicula)
				return true;
		}
	}
	return false;
}
