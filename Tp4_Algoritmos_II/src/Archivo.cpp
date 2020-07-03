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
		pelicularecomendada = false;
		for(listaVistas.iniciarIterador(iteradorVistas);!iteradorVistas.finalIterador() && !pelicularecomendada; iteradorVistas.siguiente())
		{
			peliculaVista = iteradorVistas.obtenerDato();
			if(peliculaNoVista->recomendarPelicula(peliculaVista))
			{
				listaRecomendados.insertar(peliculaNoVista);
				pelicularecomendada = true;
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
    //CARGO LAS VISTAS
    cargarPeliculas(listaVistas, ARCHIVO_VISTAS);

    //CARGO LAS NO VISTAS
    cargarPeliculas(listaNoVistas, ARCHIVO_NO_VISTAS);

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

//HICE ESTAS FUNCIONES PARA NO REPETIR EL CODIGO DE CARGAR LAS PELICULAS

void cargarPeliculas( Lista<Pelicula*>& lista , string rutaArchivo){

	ifstream archivo;
	archivo.open(rutaArchivo, fstream::in);
	if(archivo.fail()) {
        throw ExcepcionLectura(archivo);
        return;
    }
	string titulo, genero, director, actores, actor, puntajeString;
	double puntaje;
	string arrayActores[];

	while(!archivo.eof()){
	    getline(archivo, titulo,'\n');
	    getline(archivo, genero,'\n');
	    getline(archivo, puntajeString,'\n');
	    getline(archivo, director,'\n');
	    getline(archivo, actores,'\n');

	    puntaje = stod(puntajeString);
	    Pelicula* pelicula = new Pelicula(titulo, genero, director, puntaje);

	    string* aux;
	    while(getline(actores, actor, ' '))
	    {
	    	aux = new string(actor);
	        pelicula->insertarActor(aux);
	    }
	}
	archivo.close();
}

Archivo::~Archivo()
{
	listaRecomendados.vaciarLista();
    //dtor
}
