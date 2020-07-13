#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;
    string opcion;
    int numeroIngreado = 1;
    bool volverAIngresar = true;

    // Cargamos los datos
    menu.cargarDatos();
    menu.mostrarOpciones();

    while(numeroIngreado != OPCION_SALIR)
    {
        while(volverAIngresar)
        {
            cout << "Ingrese una opcion: ";
            volverAIngresar = false;
            cin >> opcion;
            try
            {
                numeroIngreado = stoi(opcion);
            }
            catch (...)
            {
                volverAIngresar = true;
                cout << "Opcion no disponible" << endl;
            }
        }
        switch(numeroIngreado)
        {
            case OPCION_VISTAS:
                menu.mostrarVistas();
                break;

            case OPCION_NO_VISTAS :
                menu.mostrarNoVistas();
                break;

            case OPCION_RECOMENDADAS:
                menu.mostrarRecomendacion();
                break;

            case OPCION_SALIR:
                break;

            default:
                cout << "Opcion no disponible" << endl;
                break;
            }

        // Volvemos a pedir una opcion
        volverAIngresar = true;
    }

    return 0;
}
