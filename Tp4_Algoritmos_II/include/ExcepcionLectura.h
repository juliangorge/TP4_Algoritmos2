//
// Created by tomas on 1/7/20.
//
#ifndef TP4_ALGORITMOS2_EXCEPCIONLECTURA_H
#define TP4_ALGORITMOS2_EXCEPCIONLECTURA_H

#include <iostream>
#include <exception>
using namespace std;

class ExcepcionLectura: public exception {

private:

	string mensaje;
    string archivo;

public:
    //PRE: -
    //POST: Construye la excepcion con el nombre del archivo
    ExcepcionLectura (string archivo) throw();

    //PRE: -
    //POST: devuelve un mensaje describiendo la excepcion
    virtual const char* what() const throw();

};


#endif //TP4_ALGORITMOS2_EXCEPCIONLECTURA_H
