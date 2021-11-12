#ifndef GESTOR_H
#define GESTOR_H


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
    struct  Comparador{


        bool operator()(Cliente & c1,Cliente & c2)
        {

            return c1.getLlegada()<c2.getLlegada();

        }


    };

};


#endif // GESTOR_H
