#include "ColaCliente.h"
#include "iostream"

using namespace std;

ColaCliente::ColaCliente() {

    primero = NULL;
    ultimo = NULL;
    longitud =0;
    //Constructor de ColaCliente

}
void ColaCliente::encolar(Cliente c) {

    NodoCola *nodo = new NodoCola(c);
    if(esVacia()){
        primero = nodo;
        ultimo = nodo;

    }
    else{

        ultimo->siguiente = nodo;
        ultimo = nodo;

    }
    longitud++;


}

Cliente ColaCliente::desencolar() {

    if(!esVacia()){
        Cliente c = primero->cliente;
        NodoCola *aux= primero;
        if((primero==ultimo)&&(primero->siguiente==NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);


        }
        longitud--;
        return c;

    }


}

Cliente ColaCliente::inicio() {

    if(!esVacia()){

        return primero->cliente;

    }


}

Cliente ColaCliente::fin() {

    if(!esVacia()){

        return ultimo->cliente;

    }

}

bool ColaCliente::esVacia() {

    return ((primero == NULL) && (ultimo ==NULL));

}
void ColaCliente::mostrarCola() {

    NodoCola *aux = primero;
    int i= 1;
    if(esVacia()){

        cout<<"COLA VACIA"<<endl;

    }
    else{

        while(aux){

            cout<<"   Cliente "<<i<<endl;
            cout<<"------------------"<<endl;
            aux->cliente.toString();
            aux = aux->siguiente;
            i++;
            cout<<"\n";
        }


    }

}

ColaCliente::~ColaCliente() {

}
