#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() {

    //Constructor Cliente

}

Cliente::~Cliente() {

    //Destructor Cliente

}
void Cliente::setRegistrado(bool x){

    registrado = x;

}

void Cliente::setLlegada(int min){
    llegada = min;

}
void Cliente::setId(string i){

    id = i;

}
void Cliente::setTipoEntrada(int entrada){

    datosEntrada.tipoEntrada = entrada;

}
void Cliente::setIdConcierto(int id) {

    datosEntrada.idConcierto = id;

}

bool Cliente::isRegistrado() {

    if(registrado){
        return true;
    }else{
        return false;
    }

}
int Cliente::getLlegada() {

    return llegada;
}

void  Cliente::toString() {

    cout<<"[*] Identificador->"<<id<<endl;
    cout<<"[*] Registrado->"<<registrado<<endl;
    if(llegada<10){
        cout<<"[*] Tiempo de llegada-> 10:0"<<llegada<<endl;
    }else {
        cout << "[*] Tiempo de llegada-> 10:" << llegada << endl;
    }
    cout<<"[*] Tipo de entrada->"<<datosEntrada.tipoEntrada<<endl;
    cout<<"[*] Identificador del concierto->"<<datosEntrada.idConcierto<<endl;

}