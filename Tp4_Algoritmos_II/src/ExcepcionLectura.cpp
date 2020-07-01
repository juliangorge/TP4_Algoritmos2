//
// Created by tomas on 1/7/20.
//
#include "ExcepcionLectura.h"
using namespace std;

ExcepcionLectura::ExcepcionLectura (string archivo) throw()
{
    this->mensaje = "Error en la lectura del archivo: '" + archivo + "'\n";
}

virtual const char* ExcepcionLectura::what() const throw()
{
    return mensaje.c_str();
}