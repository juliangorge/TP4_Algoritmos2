#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;
    string opcion;
    int numeroIngreado = 0;

    // Cargamos los datos
    menu.cargarDatos();
    menu.mostrarOpciones();

    //Pedimos la opcion que el usuario desea.
    cout << "Ingrese una opcion: ";cin >> numeroIngreado;

    while(numeroIngreado != OPCION_SALIR)
    {
        switch(numeroIngreado)
        {
            case OPCION_VISTAS:
                menu.mostrarVistas();

                break;

            case OPCION_NO_VISTAS :
                menu.mostrarNoVistas();

                break;

            case OPCION_RECOMENDADAS:
                cout << "Creemos que las peliculas que deberias mirar son : \n"<<endl;
                menu.mostrarRecomendacion();

                break;

            default:
                cout << "Opcion no disponible , ingrese nuevamente." << endl;
                break;
            }

            //Termina de mostrar la lista y vuelve a mostrar el menu y pedir opciones.
            menu.mostrarOpciones();
            cout << "Ingrese una opcion: ";cin >> numeroIngreado;
    }

    //Mostramos la despedida
    menu.despedida();

    return 0;
}
