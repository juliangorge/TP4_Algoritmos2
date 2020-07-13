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

//PRE -
//POST: Muestra la lista de no vistas
void Menu::mostrarNoVistas()
{
    listas.mostrarse(listas.getListaNoVistas());
}

//PRE -
//POST: Muestra la lista de vistas
void Menu::mostrarVistas()
{
    listas.mostrarse(listas.getListaVistas());
}

//PRE -
//POST: Genera las listas
void Menu::cargarDatos()
{
    listas.generarListas();
    cout << "Se han cargado los datos correctamente! " << endl;
    listas.armarRecomendada();
}

void Menu::mostrarOpciones()
{
    cout << "\n Bienvenido \n" << endl;
    cout << " 1 - Mostrar peliculas vistas " << endl;
    cout << " 2 - Mostrar peliculas no vistas " << endl;
    cout << " 3 - Recomendacion de peliculas " << endl;
}

Menu::~Menu()
{
    // Destructor
}
