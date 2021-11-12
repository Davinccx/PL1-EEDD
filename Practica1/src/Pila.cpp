#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    while(cima) desapilar();
}

bool Pila::esVacia()
{
    return cima == NULL;
}

void Pila::apilar(Cliente c)
{
    pnodo nuevo = new NodoPila(c,cima);
    cima = nuevo;
}

void Pila::apilarRegistrado(Cliente c) {
    Pila aux;
    if(esVacia()){
        apilar(c);
    }
    else if(c.isRegistrado()  && !cima->cliente.isRegistrado()){
        apilar(c);
    }
    else{
        while(!esVacia() && !c.isRegistrado() && cima->cliente.isRegistrado()){
            aux.apilar(cima->cliente);
            desapilar();
        }
        apilar(c);
        while(!aux.esVacia()){
            apilar(aux.cima->cliente);
            aux.desapilar();
        }
    }
}


void Pila::desapilar()
{ pnodo nodo;
    if(cima)
        nodo = cima;
    cima = nodo->siguiente;
    delete nodo;
}
void Pila::verPila() {

    if(esVacia()){
    cout<<"PILA VACIA";
    }
    int i =1;
    pnodo aux = cima;
    while(aux != NULL){
        cout<<"Cliente "<<i<<endl;
        cout<<"------------------"<<endl;
        aux->cliente.toString();
        aux = aux->siguiente;
        i++;
        cout<<"\n";
    }


}

Cliente Pila::mostrarCima() {

    return cima->cliente;

}
