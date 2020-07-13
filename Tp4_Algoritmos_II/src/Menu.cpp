#include "Menu.h"

Menu::Menu()
{

}

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
    listas.generarListas();
    cout << "Se han cargado los datos correctamente! " << endl;

    listas.armarRecomendada();
}

void Menu::mostrarOpciones()
{
    cout << "\nBIENVENIDO \n" << endl;
    cout << " 1 - Mostrar peliculas vistas " << endl;
    cout << " 2 - Mostrar peliculas no vistas " << endl;
    cout << " 3 - Recomendacion de peliculas " << endl;
    cout << " 0 - Salir " << endl;
}

Menu::~Menu()
{
    // Destructor
}
