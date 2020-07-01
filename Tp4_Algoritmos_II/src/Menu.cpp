#include "Menu.h"


Menu::Menu()
{

}

//PRE -
//POST: Muestra la lista de recomendacion
void Menu::mostrarRecomendacion(){

    //Muestra  la lista de Recomendaciones
    listas.mostrarse(listas.getListaRecomendados());

}
void Menu::mostrarNoVistas()
{
    //Muestra  la lista de no vistas
    listas.mostrarse(listas.getListaNoVistas());

}
void Menu::mostrarVistas()
{
    //Muestra  la lista de vistas
    listas.mostrarse(listas.getListaVistas());
}

void Menu::cargarDatos()
{
    //Generamos las listas correspondientes
    listas.generarListas();
    cout << "Se han cargado los datos correctamente! "<<endl;
}

void Menu::mostrarOpciones()
{
    cout << "Bienvenido " <<end;
    cout << "\n 1 - Mostrar peliculas vistas "<<endl;
    cout << " 2 - Mostrar peliculas  no vistas "<<endl;
    cout << " 3 - Recomendacion de  peliculas "<<endl;
}


Menu::~Menu()
{
    //dtor
}
