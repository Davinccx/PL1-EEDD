#ifndef PRACTICA_PILA_H
#define PRACTICA_PILA_H
#include "NodoPila.h"

class Pila {

private:
    pnodo cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void apilar(Cliente c);
    void apilarRegistrado(Cliente c);
    void desapilar();
    void verPila();
    Cliente mostrarCima();


};


#endif //PRACTICA_PILA_H
