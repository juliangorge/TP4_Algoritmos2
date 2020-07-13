#ifndef EXCEPCIONLECTURA_H
#define EXCEPCIONLECTURA_H

#include <iostream>
#include <exception>

using namespace std;

class ExcepcionLectura: public exception {

private:
	string mensaje;

public:

    //Constructor de la excepcion con el nombre del archivo
    ExcepcionLectura(string archivo) throw();

    //Destructor
    virtual ~ExcepcionLectura() throw();

    //PRE: -
    //POST: devuelve un mensaje describiendo la excepcion
    virtual const char* what() const throw();

};

#endif //EXCEPCIONLECTURA_H