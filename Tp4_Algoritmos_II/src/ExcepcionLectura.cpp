//
// Created by tomas on 1/7/20.
//
#include "../include/ExcepcionLectura.h"
using namespace std;

ExcepcionLectura::ExcepcionLectura (string archivo) throw()
{
    this->archivo = archivo;
}
virtual const char* ExcepcionLectura::what() const throw()
{
    return "\n Error en la lectura del archivo: "<< archivo << endl;
}