#include "Archivo.h"

Archivo::Archivo()
{

}

//PRE: Peliculas vistas y no vistas ya cargadas
void armarRecomendada(){
	/*
	Lista recomendada:
	Pelicula -> género, director, actores
	Se recomienda comparando la lista de NO VISTAS, si [ coincide el genero Y director / 1 actor ] o puntaje >= 7
	*/

}

//GETTERS DE LAS LISTAS

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
    cargarPeliculas(getListaVistas(),archivoVistas);

    //CARGO LAS NO VISTAS
    cargarPeliculas(getListaNoVistas(),archivoNoVistas);

}

void Archivo::mostrarse(Lista<Pelicula*> &lista)
{
    for(unsigned i = 0 ; i <= lista.get_tam ; i++)
    {
        //El dato es un puntero a pelicula
        lista.get_dato(i)->mostrarPelicula();
    }
}

//HICE ESTAS FUNCIONES PARA NO REPETIR EL CODIGO DE CARGAR LAS PELICULAS


//PRE: Recibe un archivo txt
//POST: Carga las peliculas a las listas
void cargarPeliculas(ifstream& archivoVistas, ifstream& archivoNoVistas){

	string titulo, genero,director, actores;
	double puntaje;
	string arrayActores[];

    //FALTA ABRIR Y CERRAR LOS ARCHIVOS

	while(!archivoVistas.oef()){
		getline(archivoVistas, titulo,'\n');
		getline(archivoVistas, genero,'\n');
		getline(archivoVistas, puntaje,'\n');
		getline(archivoVistas, director,'\n');
		getline(archivoVistas, actores,'\n');

        Pelicula* pelicula = new Pelicula(titulo, genero, director, puntaje,);

		while(getline(actores, actor, ' ')){
			//...
		}



		// Sugerencia: Imprimir "Nueva pelicula vista cargada!"
	}

	// ¿Mismo código que archivoVistas?
	while(!archivoNoVistas.oef()){
		getline(archivoNoVistas, titulo,'\n');
		getline(archivoNoVistas, genero,'\n');
		getline(archivoNoVistas, puntaje,'\n');
		getline(archivoNoVistas, director,'\n');
		getline(archivoNoVistas, actores,'\n');

		while(getline(actores, actor, ' ')){
			//...
		}

		Pelicula* pelicula = new Pelicula(titulo, genero,director,puntaje);
		// Sugerencia: Imprimir "Nueva pelicula no vista cargada!"

		if(puntaje >= 7) armarRecomendada(titulo, genero, director, actores);
	}
}

Archivo::~Archivo()
{
    //dtor
}
