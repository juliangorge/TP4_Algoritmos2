#ifndef NODO_TEMPLATE_H
#define NODO_TEMPLATE_H

#include <iostream>

using namespace std;

template<class Dato>
class Nodo
{
 private:
     Dato dato; // Dato a almacenar
     Nodo* psig; // Puntero a otro nodo
 public:

     // PRE: Ninguna
     // POST: Crea un nodo con el dato d
     // y el puntero a NULL
     Nodo(Dato d);

     // PRE: Nodo creado
     // POST: No hace nada
     virtual ~Nodo();

     // PRE: el nodo tiene que estar creado
     // POST: El nodo queda con el dato d
     void set_dato(Dato d);

     // PRE: nodo creado
     // POST: devuelve el dato que contiene el nodo
     Dato get_dato();

     // PRE: nodo creado
     // POST: el puntero al siguiente nodo apuntará a ps
     void set_siguiente(Nodo* ps);

     // PRE: nodo creado
     // POST: Devuelve el puntero al siguiente nodo
     Nodo* get_siguiente();

     Nodo** get_puntero_siguiente();
};


/////////////////////////////////////////////////////////////////
template<class Dato>
Nodo<Dato>::Nodo(Dato d)
{

    //EL dato es un puntero a objeto
    dato = d;
    psig = 0;

}
template<class Dato>
Nodo<Dato>::~Nodo()
{
    //Como el dato tiene memoria reservada , debo liberarla
	if (dato != 0)
		delete dato;
}

template<class Dato>
void Nodo<Dato>::set_dato(Dato d)
{
    dato = d; //EL dato es un puntero a objeto
    cout<<dato<<endl;
}

template<class Dato>
Dato Nodo<Dato>::get_dato()
{
    return dato;
}

template<class Dato>
void Nodo<Dato>::set_siguiente(Nodo* ps)
{
    psig = ps;

}

template<class Dato>
Nodo<Dato>* Nodo<Dato>::get_siguiente()
{
    return psig;
}

template<class Dato>
Nodo<Dato>** Nodo<Dato>::get_puntero_siguiente()
{
    return &psig;
}



#endif // NODO_TEMPLATE_H
