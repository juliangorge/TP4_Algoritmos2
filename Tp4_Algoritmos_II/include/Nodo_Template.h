#ifndef NODO_TEMPLATE_H
#define NODO_TEMPLATE_H


template<typedef Dato>
class Nodo_Template
{
 private:
     Dato dato; // Dato a almacenar
     Nodo_Template* psig; // Puntero a otro nodo
 public:

     // PRE: Ninguna
     // POST: Crea un nodo con el dato d
     // y el puntero a NULL
     Nodo_Template(Dato d);

     // PRE: Nodo creado
     // POST: No hace nada
     ~Nodo_Template();

     // PRE: el nodo tiene que estar creado
     // POST: El nodo queda con el dato d
     void set_dato(Dato d);

     // PRE: nodo creado
     // POST: devuelve el dato que contiene el nodo
     Dato get_dato();

     // PRE: nodo creado
     // POST: el puntero al siguiente nodo apuntará a ps
     void set_siguiente(Nodo_Template* ps);

     // PRE: nodo creado
     // POST: Devuelve el puntero al siguiente nodo
     Nodo_Template* get_siguiente();
};


/////////////////////////////////////////////////////////////////
template<typedef Dato>
Nodo<Dato>::Nodo(Dato d)
{

    //EL dato es un puntero a objeto
    dato = d;
    psig = 0;

}
Nodo<Dato>::~Nodo()
{
    //Como el dato tiene memoria reservada , debo liberarla
    delete dato;
}

template<typedef Dato>
void Nodo<Dato>::set_dato(Dato d)
{
    dato = d; //EL dato es un puntero a objeto
    cout<<dato<<endl;
}

template<typedef Dato>
Dato Nodo<Dato>::get_dato()
{
    return dato;
}

template<typedef Dato>
void Nodo<Dato>::set_siguiente(Nodo* ps)
{
    psig = ps;

}

template<typedef Dato>
Nodo<Dato>* Nodo<Dato>::get_siguiente()
{
    return psig;
}


#endif // NODO_TEMPLATE_H
