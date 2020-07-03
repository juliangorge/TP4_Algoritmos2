#ifndef ARCHIVO_H
#define ARCHIVO_H

#include"Lista_Template.h"
#include"Pelicula.h"
#include"ExcepcionLectura.h"

const string ARCHIVO_VISTAS = "peliculas_vistas.txt";
const string ARCHIVO_NO_VISTAS = "peliculas_no_vistas.txt";


//Clase Archivo encargada del manejo de archivo
class Archivo
{
    private:

        //Listas cuyo tipo de dato es un puntero a una pelicula.
        Lista<Pelicula*> listaVistas ;
        Lista<Pelicula*> listaNoVistas ;
        Lista<Pelicula*> listaRecomendados ;

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
        //POST:Devuelve la lista vista
        Lista<Pelicula*> getListaVistas();

        //PRE:-
        //POST:Devuelve la lista vista
        Lista<Pelicula*> getListaNoVistas();

        //PRE:-
        //POST:Devuelve la lista vista
        Lista<Pelicula*> getListaRecomendados();


        //PRE: Recibe una lista y una ruta de tipo string archivo txt
        //POST: Carga las peliculas a las listas
        void cargarPeliculas( Lista<Pelicula*> &lista , string rutaArchivo);

        //PRE: Recibe la lista a mostrar
        //POST: Muestra TODOS los elementos de la lista
        void mostrarse(Lista<Pelicula*> &lista);

        //Destructor
        ~Archivo();

};

#endif // ARCHIVO_H
