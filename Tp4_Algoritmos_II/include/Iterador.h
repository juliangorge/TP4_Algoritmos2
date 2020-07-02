#ifndef ITERADOR_H_
#define ITERADOR_H_

#include "Nodo_Template.h"

// iterador de listas
template<class Dato>
class Iterador
{
private:
	Nodo<Dato>** actual;
	unsigned* tamLista;

public:

	// constructor sin parametros
	// POST: crea un iterador
	Iterador();

	// destructor
	// POST: destruye un iterador
	virtual ~Iterador();

	// POST: setea los atributos
	void setearInicio(Nodo<Dato>** nodoInicial, unsigned* tamInicial);


	// POST: salta al siguiente elemento de la lista
	void siguiente();

	// POST: devuelve true si es el fonal de la lista
	bool finalIterador();

	// POST: devuelve el dato de la posicion actual
	Dato obtenerDato();

	// POST: devuelve el dato de la posicion actual y lo elimina de la lista
	Dato eliminarDato();

	// POST: agrega un dato ANTES del dato actual
	void agregarDato(Dato datoAgregado);
};

template<class Dato>
Iterador<Dato>::Iterador()
{
	actual = 0;
	tamLista = 0;
}

template<class Dato>
Iterador<Dato>::~Iterador()
{
	actual = 0;
	tamLista = 0;
}

template<class Dato>
void Iterador<Dato>::setearInicio(Nodo<Dato>** inicial, unsigned* tamInicial)
{
	actual = inicial;
	tamLista = tamInicial;
}

template<class Dato>
void Iterador<Dato>::siguiente()
{
	actual = (*actual)->get_puntero_siguiente();
}

template<class Dato>
bool Iterador<Dato>::finalIterador()
{
	return (*actual) == 0;
}

template<class Dato>
Dato Iterador<Dato>::obtenerDato()
{
	return (*actual)->get_dato();
}

template<class Dato>
Dato Iterador<Dato>::eliminarDato()
{
	Nodo<Dato>* nodoAuxiliar = *actual;
	Dato datoAuxiliar = nodoAuxiliar->get_dato();
	*actual = (*actual)->get_siguiente();
	delete nodoAuxiliar;

	*tamLista = (*tamLista) -1;
	return datoAuxiliar;
}

template<class Dato>
void Iterador<Dato>::agregarDato(Dato datoAgregado)
{
	Nodo<Dato>* nodoAuxiliar= new Nodo<Dato>(datoAgregado);
	Nodo<Dato>* nodoSiguiente = (*actual)->get_siguiente();
	nodoAuxiliar->set_siguiente(nodoSiguiente);

	*tamLista = (*tamLista) +1;
	*actual = nodoAuxiliar;

}

/* ejemplo de uso:
 *
	string* s1 = new string;
	*s1 = "Hola";
	string* s2 = new string;
	*s2 = "Mundo";
	string* s3 = new string;
	*s3 = ":)";
	Lista<string*> lista1;
	lista1.insertar(s1);
	lista1.insertar(s2);
	lista1.insertar(s3);

	Iterador<string*> iterador1;
	string* aux;
	for(lista1.iniciar_iterador(iterador1); !iterador1.finalIterador(); iterador1.siguiente())
	{
		aux = iterador1.obtenerDato();
		cout << *aux << " ";
	}
	cout << endl;
 */

#endif /* TP4_ALGORITMOS_II_INCLUDE_ITERADOR_H_ */
