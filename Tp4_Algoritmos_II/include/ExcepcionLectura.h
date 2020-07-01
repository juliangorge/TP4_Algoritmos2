//
// Created by tomas on 1/7/20.
//
#ifndef TP4_ALGORITMOS2_EXCEPCIONLECTURA_H
#define TP4_ALGORITMOS2_EXCEPCIONLECTURA_H

class ExcepcionLectura: public exception {

private:

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
