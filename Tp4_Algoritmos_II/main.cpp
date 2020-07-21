#include <iostream>
#include"Menu.h"
#include "ExcepcionLectura.h"

using namespace std;

int main()
{
    Menu menu;
    string opcion;
    int numeroIngreado = 1;
    bool volverAIngresar = true;

    try
    {
    	menu.cargarDatos();
    }
    catch (ExcepcionLectura& e)
	{
		cout << e.what();
		return 1;
	}

    //Cargamos los datos

    cout << "Ingrese una opcion :";
    while(numeroIngreado != OPCION_SALIR)
    {

    	while(volverAIngresar)
    	{
    	menu.mostrarOpciones();
		cout << "Ingrese una opcion :";
    		volverAIngresar = false;
        	cin >> opcion;
        	try
        	{
        		numeroIngreado = stoi(opcion);
        	}
        	catch (...)
        	{
        		volverAIngresar = true;
        		cout << "Opcion no disponible"<<endl;
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
            cout << "Opcion no disponible"<<endl;
            break;
        }

        //Volvemos a pedir una opcion

        volverAIngresar = true;
    }

    //Mostramos la despedida
    menu.despedida();

    return 0;
}
