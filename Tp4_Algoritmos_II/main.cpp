#include"Menu.h

int main()
{
    Menu menu;
    int opcion;

    //Cargariamos los datos
    menu.cargarDatos();

    menu.mostrarOpciones();
    cout << "Ingrese una opcion :"; cin >> opcion ;
    while(opcion != OPCION_SALIR)
    {
        switch(opcion)
        {
        case OPCION_VISTAS:
            menu.mostrarVistas();
        }
        case OPCION_NO_VISTAS:
            menu.mostrarNoVistas();
        }
        case OPCION_RECOMENDADAS:
            menu.mostrarRecomendadas();
        }
        default:
            cout << "Opcion no disponible"<<endl;

        //Volvemos a pedir una opcion
        cout << "Ingrese una opcion :"; cin >> opcion ;
    };

    return 0;
}
