#include "NodoPila.h"

NodoPila::NodoPila()
{
    Cliente c;
    cliente = c;
    siguiente=NULL;
//ctor
}
NodoPila::NodoPila(Cliente c, NodoPila *sig)
{
    cliente = c;
    siguiente = sig;
}
NodoPila::~NodoPila()
{
//dtor
}