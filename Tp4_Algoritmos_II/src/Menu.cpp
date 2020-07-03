#include "Menu.h"


Menu::Menu()
{

}

//PRE -
//POST: Muestra la lista de recomendacion
void Menu::mostrarRecomendacion(){
    Lista<Pelicula*> listaAux = listas.getListaRecomendados();

    //Muestra  la lista de Recomendaciones
    listas.mostrarse(listaAux);

}
void Menu::mostrarNoVistas()
{
    Lista<Pelicula*> listaAux = listas.getListaNoVistas();
    //Muestra  la lista de no vistas
    listas.mostrarse(listaAux);

}
void Menu::mostrarVistas()
{
     Lista<Pelicula*> listaAux = listas.getListaVistas();
    //Muestra  la lista de vistas
    listas.mostrarse(listaAux);
}

void Menu::cargarDatos()
{
    //Generamos las listas correspondientes
    listas.generarListas();
    cout << "Se han cargado los datos correctamente! "<<endl;
}

void Menu::mostrarOpciones()
{
    cout << "Bienvenido " <<endl;
    cout << "\n 1 - Mostrar peliculas vistas "<<endl;
    cout << " 2 - Mostrar peliculas  no vistas "<<endl;
    cout << " 3 - Recomendacion de  peliculas "<<endl;
}


Menu::~Menu()
{
    //dtor
}
