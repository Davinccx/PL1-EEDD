#ifndef COLACLIENTE_H
#define COLACLIENTE_H


#include "NodoCola.h"
#include "Cliente.h"

class ColaCliente {
private:
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;

public:
    ColaCliente();
    ~ColaCliente();
    void encolar(Cliente c);
    Cliente inicio();
    Cliente fin();
    Cliente desencolar();
    bool esVacia();
    void mostrarCola();

};

#endif // COLACLIENTE_H
