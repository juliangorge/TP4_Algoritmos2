#ifndef ARCHIVO_H
#define ARCHIVO_H

#include"Lista_Template.h"
#include"Pelicula.h"

const string archivoVistas = "peliculas_vistas.txt";
const string archivoNoVistas = "peliculas_no_vistas.txt";


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

        //Destructor
        ~Archivo();

};

#endif // ARCHIVO_H
