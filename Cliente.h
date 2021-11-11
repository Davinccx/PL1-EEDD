
#ifndef PRACTICA_CLIENTE_H
#define PRACTICA_CLIENTE_H
#include <iostream>
#include <string.h>

class Cliente {

public:

    Cliente();
    ~Cliente();
    void setRegistrado(bool x);
    void setLlegada(int min);
    void setId(std::string i);
    void setTipoEntrada(int entrada);
    int getLlegada();
    void setIdConcierto(int id);
    bool isRegistrado();
    void toString();

private:

    bool registrado;
    int llegada;
    std::string id;
    struct {
        int tipoEntrada;
        int idConcierto;



    }datosEntrada;


};


#endif //PRACTICA_CLIENTE_H
