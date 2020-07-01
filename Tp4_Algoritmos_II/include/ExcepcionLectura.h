//
// Created by tomas on 1/7/20.
//
#ifndef TP4_ALGORITMOS2_EXCEPCIONLECTURA_H
#define TP4_ALGORITMOS2_EXCEPCIONLECTURA_H

class ExcepcionLectura: public exception {

private:

    string archivo;

public:
    //FALTAN LOS PRE Y POST
    ExcepcionLectura(string archivo) throw();
    virtual const char* what() const throw();

};


#endif //TP4_ALGORITMOS2_EXCEPCIONLECTURA_H
