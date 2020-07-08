#include "Pelicula.h"
#include "Iterador.h"


Pelicula::Pelicula(string nombre, string genero, string director , double puntaje)
{
    //Atributos
    this->nombre   = nombre;
    this->genero   = genero;
    this->director = director;
    this->puntaje  = puntaje;


}

bool Pelicula::buscarActorEnPelicula(string* actor, Pelicula* pelicula)
{
	Iterador<string*> otraPelicula;
	string* actorOtraPelicula;
	for(pelicula->actores.iniciarIterador(otraPelicula); !otraPelicula.finalIterador(); otraPelicula.siguiente())
	{
		actorOtraPelicula = otraPelicula.obtenerDato();
		if(*actor == *actorOtraPelicula)
			return true;
	}
	return false;
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

void Pelicula::mostrarActores()
{
	Iterador<string*> iteradorActores;
	string* aux;
    for(actores.iniciarIterador(iteradorActores); !iteradorActores.finalIterador(); iteradorActores.siguiente())
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
    cout<<"Actores: \n";
    mostrarActores();
    cout<<endl;
}

/*Pelicula::~Pelicula()
{

}*/

bool Pelicula::verificarPuntaje()
{
	return puntaje >= 7;
}

bool Pelicula::compararGenero(Pelicula* peliculaAComparar)
{
	return genero == peliculaAComparar->genero;
}

bool Pelicula::compararDirector(Pelicula* peliculaAComparar)
{
	return director == peliculaAComparar->director;
}

bool Pelicula::compararActores(Pelicula* peliculaAComparar)
{
	Iterador<string*> estaPelicula;
	string* actorEstaPelicula;
	for(actores.iniciarIterador(estaPelicula); !estaPelicula.finalIterador(); estaPelicula.siguiente())
	{
		actorEstaPelicula = estaPelicula.obtenerDato();
		if(buscarActorEnPelicula(actorEstaPelicula, peliculaAComparar))
			return true;
	}
	return false;
}

bool Pelicula::recomendarPorComparacion(Pelicula* peliculaAComparar)
{
	if (!compararGenero(peliculaAComparar))
		return false;
	if (compararDirector(peliculaAComparar))
		return true;
	if (compararActores(peliculaAComparar))
		return true;
	return false;
}
