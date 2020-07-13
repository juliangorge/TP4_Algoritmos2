#include "Menu.h"


Menu::Menu()
{

}

//PRE -
//POST: Muestra la lista de recomendacion
void Menu::mostrarRecomendacion()
{
    listas.mostrarse(listas.getListaRecomendados());
}
void Menu::mostrarNoVistas()
{
    listas.mostrarse(listas.getListaNoVistas());
}
void Menu::mostrarVistas()
{
    listas.mostrarse(listas.getListaVistas());
}

void Menu::cargarDatos()
{
    //Generamos las listas correspondientes
    listas.generarListas();
    cout << "Se han cargado los datos correctamente! "<<endl;
    listas.armarRecomendada();
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
