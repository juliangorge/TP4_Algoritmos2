#include "Archivo.h"
#include <fstream>

#include "Iterador.h"

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
    Lista<Pelicula*> listaAux = getListaVistas();
    Lista<Pelicula*> listaAux2 = getListaNoVistas();
    //CARGO LAS VISTAS
    cargarPeliculas(listaAux,archivoVistas);

    //CARGO LAS NO VISTAS
    cargarPeliculas(listaAux2,archivoNoVistas);

}

void Archivo::mostrarse(Lista<Pelicula*>& lista)
{
    for(unsigned i = 1 ; i <= lista.getTam() ; i++)
    {
        //El dato es un puntero a pelicula
        lista.getDato(i)->mostrarPelicula();
    }
}

//HICE ESTAS FUNCIONES PARA NO REPETIR EL CODIGO DE CARGAR LAS PELICULAS


//PRE: Recibe un archivo txt
//POST: Carga las peliculas a las listas
void cargarPeliculas( Lista<Pelicula*>& lista , string rutaArchivo){

	ifstream archivo;
	archivo.open(rutaArchivo, fstream::in);
	if(!archivo){

		string titulo, genero, director, actores;
		double puntaje;
		string arrayActores[];

		while(!archivo.eof()){
			getline(archivoVistas, titulo,'\n');
			getline(archivoVistas, genero,'\n');
			getline(archivoVistas, puntaje,'\n');
			getline(archivoVistas, director,'\n');
			getline(archivoVistas, actores,'\n');

	        Pelicula* pelicula = new Pelicula(titulo, genero, director, puntaje);

			while(getline(actores, actor, ' ')){
				pelicula->insertarActor(&actor);
			}
		}

		archivo.close();
	}else{
		cout << "No se pudo abrir el archivo" << endl;
	}
}

Archivo::~Archivo()
{
	listaRecomendados.vaciarLista();
    //dtor
}
