#ifndef NODOCOLA_H
#define NODOCOLA_H


#include <iostream>
#include "Cliente.h"

class NodoCola {
friend class ColaCliente;

private:
    NodoCola *siguiente;
    Cliente cliente;
public:
    NodoCola();
    NodoCola(Cliente c,NodoCola *sig =NULL);
    ~NodoCola();
};

#endif // NODOCOLA_H
