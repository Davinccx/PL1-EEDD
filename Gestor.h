#ifndef PRACTICA_GESTOR_H
#define PRACTICA_GESTOR_H

#include "Cliente.h"
#include <list>
#include <iostream>

using namespace std;

class Gestor {
public:
    Gestor();
    ~Gestor();
    list<Cliente> generarCliente(int numCliente);
    list<Cliente> generarClienteRegistrado(int numCliente);
    list<Cliente> generarClienteNoRegistrado(int numCliente);
    string generarDNI();
    void menu();
private:

};


#endif //PRACTICA_GESTOR_H
