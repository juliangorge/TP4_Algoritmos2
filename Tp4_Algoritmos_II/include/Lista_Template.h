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

     bool listaVacia();

     // PRE: lista creada
     // POST: agrega un dato (dentro de un nodo) al final
     void insertar(Dato d);

     // PRE: - lista creada y no vacia
     // POST: devuelve el dato que esta en la posicion pos
     Dato getDato(unsigned pos);

     // PRE: - lista creada y no vacia
     // POST: libera el nodo que esta en la posici�n pos
     void delDato(unsigned pos);

     // PRE: Lista creada
     // POST: Devuelve tam (cantidad de nodos de la lista)
     unsigned getTam();

     // POST: vacia la lista sin borrar los datos
     void vaciarLista();

     // PRE: iterador debe estar creado
     // POST: inicializa el iterador
     void iniciarIterador(Iterador<Dato>& iteradorLista);
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
    while (!(this->listaVacia()))
        this->delDato(1);
}


template<class Dato>
bool Lista<Dato>::listaVacia()
{
    return(primero == 0);
}

template<class Dato>
void Lista<Dato>::insertar(Dato d)
 {
    Nodo<Dato>* pnodo = new Nodo<Dato>(d);
    Nodo<Dato>* paux = primero;
    if (this->listaVacia()){
        primero = pnodo;
    }
    else{
        while (paux->getSiguiente() != 0){
            paux = paux->getSiguiente();
        }
        paux->setSiguiente(pnodo);
 }
 tam++;
}



template<class Dato>
Dato Lista<Dato>::getDato(unsigned pos)
{
    Nodo<Dato>* paux = primero;

    unsigned i = 1;
    while (i < pos && paux->getSiguiente())
    {
        paux = paux->getSiguiente();
        i++;
    }

    return paux->getDato();
}


template<class Dato>
void Lista<Dato>::delDato(unsigned pos)
{
   Nodo<Dato>* paux = primero;
    if (pos == 1 || !(primero->getSiguiente()))
    {
        primero = paux->getSiguiente();
    }
    else
    {
        unsigned i = 1;
        Nodo<Dato>* pant;
        while (i < pos && paux->getSiguiente())
        {
            pant = paux;
            paux = paux->getSiguiente();
            i++;
        }
        pant->setSiguiente(paux->getSiguiente());
    }
    delete paux;
    tam--;
}


template<class Dato>
unsigned Lista<Dato>::getTam()
{
    return tam;
}

template<class Dato>
void Lista<Dato>::vaciarLista()
{
    while (!(this->listaVacia()))
    {
    	primero->setDato(0);
        this->delDato(1);
    }

}


template<class Dato>
void Lista<Dato>::iniciarIterador(Iterador<Dato>& iteradorLista)
{
	iteradorLista.setInicio(&primero, &tam);
}

#endif // LISTA_TEMPLATE_H
