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

//PRE: Recibe un archivo txt
//POST: Carga las peliculas a las listas
void cargarPeliculas(ifstream& archivoVistas, ifstream& archivoNoVistas){
	
	string titulo, genero, puntaje, director, actores;
	string arrayActores[];

	while(!archivoVistas.oef()){
		getline(archivoVistas, titulo);
		getline(archivoVistas, genero);
		getline(archivoVistas, puntaje);
		getline(archivoVistas, director);
		getline(archivoVistas, actores);

		while(getline(actores, actor, ' ')){
			//...
		}


		Pelicula* pelicula = new Pelicula(titulo, genero, puntaje, director, actores);
		// Sugerencia: Imprimir "Nueva pelicula vista cargada!"
	}

	// ¿Mismo código que archivoVistas?
	while(!archivoNoVistas.oef()){
		getline(archivoNoVistas, titulo);
		getline(archivoNoVistas, genero);
		getline(archivoNoVistas, puntaje);
		getline(archivoNoVistas, director);
		getline(archivoNoVistas, actores);

		while(getline(actores, actor, ' ')){
			//...
		}

		Pelicula* pelicula = new Pelicula(titulo, genero, puntaje, director, actores);
		// Sugerencia: Imprimir "Nueva pelicula no vista cargada!"

		if(puntaje >= 7) armarRecomendada(titulo, genero, director, actores);
	}
}

Archivo::~Archivo()
{
    //dtor
}