#ifndef ARCHIVO_H
#define ARCHIVO_H

#include"Lista_Template.h"
#include"Pelicula.h"


const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";


//Clase Archivo encargada del manejo de archivo
class Archivo
{
    private:

        //Listas cuyo tipo de dato es un puntero a una pelicula.
        Lista<Pelicula*> listaVistas;
        Lista<Pelicula*> listaNoVistas;
        Lista<Pelicula*> listaRecomendados;

        //POST: compara una pelicula con las peliculas de la lista de vistas. Devuelve true si la recomienda
        bool recomedarPelicula(Pelicula* peliculaNoVista);

        //POST: intenta crear el archivo de peliculas vistas. Devuleve true en caso afirmativo
        bool crearArchivoVistas();
    public:

        //Constructor

        Archivo();

        //PRE: Peliculas vistas y no vistas ya cargadas
        //POST: Carga las recomendadas a lista
        void armarRecomendada();

        //PRE:-
        //POST:Genera ambas listas.
        void generarListas();

        //PRE:-
        //POST:Devuelve la lista de peliculas vistas
        Lista<Pelicula*>& getListaVistas();

        //PRE:-
        //POST:Devuelve la lista de peliculas no vistas
        Lista<Pelicula*>& getListaNoVistas();

        //PRE:-
        //POST:Devuelve la lista de peliculas recomendadas
        Lista<Pelicula*>& getListaRecomendados();

        //POST: Carga en listaVistas las peliculas vistas de un archovo
        void cargarPeliculasVistas();

        //POST: Carga en listaNoVistas las peliculas vistas de un archovo
		void cargarPeliculasNoVistas();

        //PRE: Recibe una lista y una ruta de tipo string archivo txt
        //POST: Carga las peliculas a las listas
        void cargarPeliculas(Lista<Pelicula*> &lista, ifstream& archivoALeer);

        //PRE: Recibe la lista a mostrar
        //POST: Muestra TODOS los elementos de la lista
        void mostrarse(Lista<Pelicula*> &lista);

        //Destructor
        ~Archivo();

    private:

        //PRE: recibe un string con todos los actores separados por un espacio
        //POST: inserta cada actor en la pelicula
        void insertarActores(string actores, Pelicula* pelicula);

};

#endif // ARCHIVO_H
