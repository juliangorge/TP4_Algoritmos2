#include"Menu.h"

int main()
{
    Menu menu;
    int opcion;

    //Cargamos los datos
    menu.cargarDatos();

    menu.mostrarOpciones();
    cout << "Ingrese una opcion :"; cin >> opcion ;
    while(opcion != OPCION_SALIR)
    {
        switch(opcion)
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

            default:
            cout << "Opcion no disponible"<<endl;
        }

        //Volvemos a pedir una opcion
        cout << "Ingrese una opcion :";
        cin >> opcion ;
    }

    return 0;
}
