#ifndef NODOPILA_H
#define NODOPILA_H


#include <iostream>
#include "Cliente.h"

class NodoPila {
private:
    Cliente cliente;
    NodoPila *siguiente;
    friend class Pila;

public:
    NodoPila();
    NodoPila(Cliente c,NodoPila *sig);
    ~NodoPila();


};

typedef NodoPila *pnodo;

#endif // NODOPILA_H
