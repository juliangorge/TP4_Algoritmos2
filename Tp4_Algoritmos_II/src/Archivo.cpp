#include <fstream>

#include "Archivo.h"
#include "Iterador.h"
#include "ExcepcionLectura.h"

Archivo::Archivo()
{

}

bool Archivo::recomedarPelicula(Pelicula* peliculaNoVista)
{
	Iterador<Pelicula*> iteradorVistas;
	Pelicula* peliculaVista;
	if(peliculaNoVista->verificarPuntaje()){
		return true;
	}
	else
	{
		for(listaVistas.iniciarIterador(iteradorVistas); !iteradorVistas.finalIterador(); iteradorVistas.siguiente())
		{
			peliculaVista = iteradorVistas.obtenerDato();
			if(peliculaNoVista->recomendarPorComparacion(peliculaVista))
				return true;
		}
	}
	return false;
}

bool Archivo::crearArchivoVistas()
{
    ofstream archivoVistas(ARCHIVO_VISTAS);

    if(!archivoVistas.fail()){
    	archivoVistas.close();
    	return true;
    }
    return false;
}

void Archivo::armarRecomendada()
{
	Iterador<Pelicula*> iteradorNoVistas;
	Iterador<Pelicula*> iteradorRecomendadas;
	Pelicula* peliculaNoVista;

	listaRecomendados.iniciarIterador(iteradorRecomendadas);
	iteradorRecomendadas.apuntarFinalLista();

	for(listaNoVistas.iniciarIterador(iteradorNoVistas); !iteradorNoVistas.finalIterador(); iteradorNoVistas.siguiente())
	{
		peliculaNoVista = iteradorNoVistas.obtenerDato();
		if(recomedarPelicula(peliculaNoVista))
		{
			iteradorRecomendadas.agregarDato(peliculaNoVista);
			iteradorRecomendadas.siguiente();
		}
	}

}

// GETTERS DE LAS LISTAS (DEVUELVEN LA LISTA PARA MANEJAR)

Lista<Pelicula*>& Archivo::getListaNoVistas()
{
    return listaNoVistas;
}

Lista<Pelicula*>& Archivo::getListaVistas()
{
    return listaVistas;
}

Lista<Pelicula*>& Archivo::getListaRecomendados()
{
    return listaRecomendados;
}

void Archivo::generarListas()
{
	cargarPeliculasNoVistas();
	cargarPeliculasVistas();
}

void Archivo::mostrarse(Lista<Pelicula*>& lista)
{
	//Si la lista esta vacia...
	if(lista.getTam() != 0 ){
        Iterador<Pelicula*> iteradorPeliculas;
        for(lista.iniciarIterador(iteradorPeliculas); !iteradorPeliculas.finalIterador(); iteradorPeliculas.siguiente())
        {
            // El dato es un puntero a pelicula
            iteradorPeliculas.obtenerDato()->mostrarPelicula();
        }
    }
    else{
        cout << "La lista no posee peliculas !" <<endl;
    }
}

void Archivo::insertarActores (string actores, Pelicula* pelicula)
{
    string actor = "";
    string* aux;

    for (unsigned i= 0; i < actores.length() ; ++i)
    {
    	if (actores[i] != ' ')
    		actor += actores[i];
        if (actores[i] == ' ' || i == (actores.length() - 1) )
        {
        	if(actor != "")
        	{
				aux = new string(actor);
				pelicula->insertarActor(aux);
				actor = "";
        	}
        }
    }
}

void Archivo::cargarPeliculasVistas()
{
	ifstream archivoVistas(ARCHIVO_VISTAS);
	if(archivoVistas.fail())
	{
		cout << "No se pudo encontrar el archivo " << ARCHIVO_VISTAS << endl;

		cout << "Se procedera a crear el archivo" << endl;
		if(crearArchivoVistas())
			cout << " El archivo se creo exitosamente" << endl;
		else
			cout << " No se puedo crear el archivo" << endl;
		return;
	}

    cargarPeliculas(listaVistas, archivoVistas);
    archivoVistas.close();
}

void Archivo::cargarPeliculasNoVistas()
{
    ifstream archivoNoVistas(ARCHIVO_NO_VISTAS);
    if(archivoNoVistas.fail())
    {
		throw ExcepcionLectura(ARCHIVO_NO_VISTAS);
		return;
    }

    cargarPeliculas(listaNoVistas, archivoNoVistas);
    archivoNoVistas.close();
}

void Archivo::cargarPeliculas( Lista<Pelicula*>& lista , ifstream& archivoALeer)
{
    string titulo, genero, director, puntajeString, actores;

    Iterador<Pelicula*> iteradorLista;

    lista.iniciarIterador(iteradorLista);
    iteradorLista.apuntarFinalLista();

    if(!archivoALeer.peek()){
    	return;
    }

    while(!archivoALeer.eof()){
	    getline(archivoALeer, titulo);
	    getline(archivoALeer, genero);
	    getline(archivoALeer, puntajeString);
	    getline(archivoALeer, director);
	    getline(archivoALeer, actores);

	    Pelicula* pelicula = new Pelicula(titulo, genero, director, stod(puntajeString));

	    insertarActores(actores, pelicula);

	    iteradorLista.agregarDato(pelicula);
	    iteradorLista.siguiente();

	    // Se lee la linea en blanco
	    getline(archivoALeer, titulo);
	}
}

Archivo::~Archivo()
{
	// Destructor
	listaRecomendados.vaciarLista(false);
}
