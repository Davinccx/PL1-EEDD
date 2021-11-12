#include "NodoCola.h"

NodoCola::NodoCola() {
    Cliente c;

    cliente = c;
    siguiente = NULL;

}

NodoCola::NodoCola(Cliente c,NodoCola*sig) {

    cliente = c;
    siguiente = sig;

}
NodoCola::~NodoCola() {


}
