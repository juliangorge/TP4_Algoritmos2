#ifndef LISTA_TEMPLATE_H
#define LISTA_TEMPLATE_H

//Include del paquete Nodo
#include "Nodo_Template.h"
#include "Iterador.h"

//Libria iostream
#include<iostream>


template<class Dato>
class Lista
{

private:

    // Primer elemento de la lista
    Nodo<Dato>* primero;

    // Tama�o de la lista
    unsigned tam;

 public:
     // Constructor
     // PRE: ninguna
     // POST: construye una lista vacia
    Lista();
     // Destructor
     // PRE: lista creada
     // POST: Libera todos los recursos de la lista
     virtual ~Lista();

     // PRE: lista creada
     // POST: devuelve verdadero si la lista es vacia

     bool lista_vacia();

     // PRE: lista creada
     // POST: agrega un dato (dentro de un nodo) al final
     void insertar(Dato d);

     // PRE: - lista creada y no vacia
     // POST: devuelve el dato que esta en la posicion pos
     Dato get_dato(unsigned pos);

     // PRE: - lista creada y no vacia
     // POST: libera el nodo que esta en la posici�n pos
     void del_dato(unsigned pos);

     // PRE: Lista creada
     // POST: Devuelve tam (cantidad de nodos de la lista)
     unsigned get_tam();

     // POST: vacia la lista sin borrar los datos
     void varciar_lista();

     // PRE: iterador debe estar creado
     // POST: inicializa el iterador
     void iniciar_iterador(Iterador<Dato>& iteradorLista);
};



//////////////////////////////////////////////////////////////////////
template<class Dato>
Lista<Dato>::Lista()
{
    primero = 0 ;
    tam = 0;
}

template<class Dato>
Lista<Dato>::~Lista()
{
    while (!(this->lista_vacia()))
        this->del_dato(1);
}


template<class Dato>
bool Lista<Dato>::lista_vacia()
{
    return(primero == 0);
}

template<class Dato>
void Lista<Dato>::insertar(Dato d)
 {
    Nodo<Dato>* pnodo = new Nodo<Dato>(d);
    Nodo<Dato>* paux = primero;
    if (this->lista_vacia()){
        primero = pnodo;
    }
    else{
        while (paux->get_siguiente() != 0){
            paux = paux->get_siguiente();
        }
        paux->set_siguiente(pnodo);
 }
 tam++;
}



template<class Dato>
Dato Lista<Dato>::get_dato(unsigned pos)
{
    Nodo<Dato>* paux = primero;

    unsigned i = 1;
    while (i < pos && paux->get_siguiente())
    {
        paux = paux->get_siguiente();
        i++;
    }

    return paux->get_dato();
}


template<class Dato>
void Lista<Dato>::del_dato(unsigned pos)
{
   Nodo<Dato>* paux = primero;
    if (pos == 1 || !(primero->get_siguiente()))
    {
        primero = paux->get_siguiente();
    }
    else
    {
        unsigned i = 1;
        Nodo<Dato>* pant;
        while (i < pos && paux->get_siguiente())
        {
            pant = paux;
            paux = paux->get_siguiente();
            i++;
        }
        pant->set_siguiente(paux->get_siguiente());
    }
    delete paux;
    tam--;
}


template<class Dato>
unsigned Lista<Dato>::get_tam()
{
    return tam;
}

template<class Dato>
void Lista<Dato>::varciar_lista()
{
    while (!(this->lista_vacia()))
    {
    	primero->set_dato(0);
        this->del_dato(1);
    }

}


template<class Dato>
void Lista<Dato>::iniciar_iterador(Iterador<Dato>& iteradorLista)
{
	iteradorLista.setearInicio(&primero, &tam);
}

#endif // LISTA_TEMPLATE_H
