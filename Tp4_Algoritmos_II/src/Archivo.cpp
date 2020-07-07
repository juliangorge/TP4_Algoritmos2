#include "Archivo.h"
#include <fstream>

#include "Iterador.h"
#include"ExcepcionLectura.h"

Archivo::Archivo()
{

}

//PRE: Peliculas vistas y no vistas ya cargadas
void Archivo::armarRecomendada()
{
	Iterador<Pelicula*> iteradorVistas;
	Iterador<Pelicula*> iteradorNoVistas;
	Pelicula* peliculaVista;
	Pelicula* peliculaNoVista;
	bool pelicularecomendada;
	for(listaNoVistas.iniciarIterador(iteradorNoVistas);!iteradorNoVistas.finalIterador(); iteradorNoVistas.siguiente())
	{
		peliculaNoVista = iteradorNoVistas.obtenerDato();
		if(peliculaNoVista->verificarPuntaje())
			listaRecomendados.insertar(peliculaNoVista);
		else
		{
			pelicularecomendada = false;
			for(listaVistas.iniciarIterador(iteradorVistas);!iteradorVistas.finalIterador() && !pelicularecomendada; iteradorVistas.siguiente())
			{
				peliculaVista = iteradorVistas.obtenerDato();

				if(peliculaNoVista->recomendarPorComparacion(peliculaVista))
				{
					listaRecomendados.insertar(peliculaNoVista);
					pelicularecomendada = true;
				}
			}
		}
	}

}

//GETTERS DE LAS LISTAS (DEVUELVEN LA LISTA PARA MANEJAR)

Lista<Pelicula*> Archivo::getListaNoVistas()
{
    return listaNoVistas;
}

Lista<Pelicula*> Archivo::getListaVistas()
{
    return listaVistas;
}

Lista<Pelicula*> Archivo::getListaRecomendados()
{
    return listaRecomendados;
}

void Archivo::generarListas()
{
    Lista<Pelicula*> AuxVistas = getListaVistas();
    Lista<Pelicula*> AuxNoVistas = getListaNoVistas();

    cargarPeliculas(AuxVistas, ARCHIVO_VISTAS);
    cargarPeliculas(AuxNoVistas, ARCHIVO_NO_VISTAS);

}

void Archivo::mostrarse(Lista<Pelicula*>& lista)
{
	Iterador<Pelicula*> iteradorPeliculas;
    for(lista.iniciarIterador(iteradorPeliculas); !iteradorPeliculas.finalIterador() ; iteradorPeliculas.siguiente())
    {
    	//El dato es un puntero a pelicula
    	iteradorPeliculas.obtenerDato()->mostrarPelicula();
    }
}

void Archivo::insertarActores (string actores, Pelicula* pelicula)
{
    string actor = "";
    string* aux;

    for (unsigned i= 0; i < actores.length() ; ++i) {
        actor += actores[i];
        if (actores[i] == ' ' || i == (actores.length() - 1) ){
            aux = new string(actor);
            pelicula->insertarActor(aux);
            actor = "";
        }
    }
}

void Archivo::cargarPeliculas( Lista<Pelicula*>& lista , string rutaArchivo)
{
    string titulo, genero, director, puntajeString, actores;
    double puntaje;

    ifstream archivo;
    archivo.open(rutaArchivo, fstream::in);
    if(archivo.fail()) {
        throw ExcepcionLectura(rutaArchivo);
        return ;
    }

	while(!archivo.eof()){
	    getline(archivo, titulo);
	    getline(archivo, genero);
	    getline(archivo, puntajeString);
	    getline(archivo, director);
	    getline(archivo, actores);

	    puntaje = stod(puntajeString);
	    Pelicula* pelicula = new Pelicula(titulo, genero, director, puntaje);

	    insertarActores(actores, pelicula);
	}
	archivo.close();
}

Archivo::~Archivo()
{
	listaRecomendados.vaciarLista(false);
    //dtor
}
