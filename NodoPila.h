#ifndef PRACTICA_NODOPILA_H
#define PRACTICA_NODOPILA_H
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

#endif //PRACTICA_NODOPILA_H
