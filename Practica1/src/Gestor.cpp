#include "Gestor.h"
#include <iostream>
#include <stdlib.h>
#include <list>
#include <iterator>
#include "Pila.h"
#include "ColaCliente.h"

using namespace std;

Gestor::Gestor() {

    //Constructor Gestor

}

Gestor::~Gestor() {

    //Destructor Gestor

}

list<Cliente> Gestor::generarCliente(int numCliente) {

    list<Cliente> listaGenerada;
    int opc;
    for(int i =0;i<numCliente;i++){
        Cliente c;
        opc = rand()%2;
        if(opc == 1){
            c.setRegistrado(true);
        }else{
            c.setRegistrado(false);
        }

        if(c.isRegistrado()){

            string cadena = "CODREG";
            if(i<10) {
                cadena += "00"+ to_string(i);
                c.setId(cadena);
            }
            else if(i>10){
                cadena+="0"+ to_string(i);
                c.setId(cadena);
            }
            else if(i>99){
                cadena+= to_string(i);
                c.setId(cadena);
            }
        }
        else{

           c.setId(generarDNI());
        }

        c.setIdConcierto(rand()%4+1);
        c.setTipoEntrada(rand()%3);
        c.setLlegada(rand()%60);

        listaGenerada.push_back(c);



    }

    listaGenerada.sort(Comparador());

    return listaGenerada;

}



list<Cliente> Gestor::generarClienteRegistrado(int numCliente) {

    list<Cliente> listaGenerada;
    for(int i =0;i<numCliente;i++){
        Cliente c;
        c.setRegistrado(true);
        string cadena = "CODREG";
        cadena+= to_string(i+000);
        c.setId(cadena);
        c.setIdConcierto(rand()%4+1);
        c.setTipoEntrada(rand()%3);
        c.setLlegada(rand()%60);

        listaGenerada.push_front(c);

    }

    listaGenerada.sort(Comparador());



    return listaGenerada;

}


list<Cliente> Gestor::generarClienteNoRegistrado(int numCliente) {

    list<Cliente> listaGenerada;
    for(int i =0;i<numCliente;i++){
        Cliente c;
        c.setRegistrado(false);
        string cadena = generarDNI();
        cadena+= to_string(i+000);
        c.setId(cadena);
        c.setIdConcierto(rand()%4+1);
        c.setTipoEntrada(rand()%3);
        c.setLlegada(rand()%60);

        listaGenerada.push_front(c);

    }

    listaGenerada.sort(Comparador());


    return listaGenerada;

}


string Gestor::generarDNI() {

        int i=0;
        int num;
        char letras[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        string dni;
        while(i<8){
            num = rand() % 10;
            dni += to_string(num);
            i++;
        }

        dni += letras[rand()%26];
        return dni;

}

void Gestor::menu(){

    int opcion;
    Pila aux;
    list<Cliente> listaEspera,listaColas,listaPila,listaCola1,listaCola2;
    Pila N;
    ColaCliente N1;
    ColaCliente N2;
    cout << "-----------------------------------------------------" << endl;
    cout << "|   BIENVENIDO A NUESTRA WEB DE VENTAS DE ENTRADAS  |" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\n";
    cout << "[!] Creando las estructuras para el correcto funcionamiento de nuestra plataforma..." << endl;
    cout<<"\n";

    while (true) {

        int numClientes,numClientes2,reg,entrada,concierto,borrarCola;
        Cliente c;
        string id;
        cout << "MENU DE OPCIONES" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "[1] Generar clientes en N, N1 Y N2"<<endl;
        cout << "[2] Generar clientes con reserva." << endl;
        cout << "[3] Generar clientes registrados y no registrados." << endl;
        cout << "[4] Incluir cliente manualmente en la PILA." << endl;
        cout << "[5] Incluir cliente manualmente en su COLA asociada." << endl;
        cout << "[6] Mostrar clientes en la PILA." << endl;
        cout << "[7] Borrar la PILA de clientes." << endl;
        cout << "[8] Mostrar COLA de clientes registrados." << endl;
        cout << "[9] Mostrar COLA de clientes no registrados." << endl;
        cout << "[10] Borrar COLAS" << endl;
        cout << "[0] Salir" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "[*] Que desea hacer? (0-10)->" << endl;
        cin >> opcion;

        switch (opcion) {

            case 1:

                listaPila = generarCliente(5);
                while(!listaPila.empty()){
                    c = listaPila.front();
                    N.apilarRegistrado(c);
                    listaPila.pop_front();
                }
                listaCola1 = generarClienteRegistrado(5);
                while(!listaCola1.empty()){
                    c = listaCola1.front();
                    N1.encolar(c);
                    listaCola1.pop_front();
                }
                listaCola2 = generarClienteNoRegistrado(5);
                while(!listaCola2.empty()){
                    c = listaCola2.front();
                    N2.encolar(c);
                    listaCola2.pop_front();
                }
            cout<<"[*] Se han generado correctamente 5 clientes en cada una de las estructuras!"<<endl;
            cout<<"\n";
                break;

            case 2:

                cout << "[!] Para comenzar debera generar un numero de clientes que tienen reserva de entrada" << endl;
                cout << "[*] Cuantos clientes deseas generar ->" << endl;
                cin >> numClientes;
                listaEspera = generarCliente(numClientes);
                while (!listaEspera.empty()) {

                    Cliente c;
                    c = listaEspera.front();
                    listaEspera.pop_front();
                    N.apilarRegistrado(c);
                }
                cout << "[*] Clientes generados y agregados a la PILA correctamente" << endl;
                cout<<"\n";
                break;

            case 3:
                cout << "[*] Cuantos clientes registrados desea generar?->";
                cin >> numClientes2;
                listaColas = generarCliente(numClientes2);
                while (!listaColas.empty()) {
                    Cliente c;
                    c = listaColas.front();
                    if (c.isRegistrado()) {
                        N1.encolar(c);
                    } else {
                        N2.encolar(c);

                    }
                    listaColas.pop_front();

                }
                cout << "[*] Clientes generados y agregados a su COLA correspondiente" << endl;
                cout<<"\n";

                break;

            case 4:
                cout<<"\n";
                cout<<"-------------------------------------------------"<<endl;
                cout<<"| CREACION DE CLIENTE E INTRODUCIRLO EN LA PILA |"<<endl;
                cout<<"-------------------------------------------------"<<endl;
                cout<<"[*] Registrado(1) o No Registrado(0)->"<<endl;
                cin>>reg;
                if(reg==1){
                    cout<<"[*] Identificador de su Cliente (CODREG...)->"<<endl;
                    cin>>id;
                    cout<<"[*] Identificador de entrada(1-5)-> "<<endl;
                    cin>>entrada;
                    cout<<"[*] Identificador de concierto(1-5)-> "<<endl;
                    cin>>concierto;
                    c.setRegistrado(true);

                }
                else if(reg==0){
                    cout<<"[*] DNI del cliente ->"<<endl;
                    cin>>id;
                    cout<<"[*] Identificador de entrada(1-5)-> "<<endl;
                    cin>>entrada;
                    cout<<"[*] Identificador de concierto(1-5)-> "<<endl;
                    cin>>concierto;
                    c.setRegistrado(false);

                }
                else{
                    cout<<"[!] Introduce un numero dentro del rango establecido"<<endl;
                    cout<<"\n";
                    break;

                }
                c.setId(id);
                c.setTipoEntrada(entrada);
                c.setIdConcierto(concierto);
                c.setLlegada(rand()%60);
                N.apilarRegistrado(c);
                cout<<"[*] Cliente agregado correctamente"<<endl;
                cout<<"\n";
                break;

            case 5:
                cout<<"\n";
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"| CREACION DE CLIENTE E INTRODUCIRLO A SU COLA CORRESPONDIENTE |"<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"[*] Registrado(1) o No Registrado(0)->"<<endl;
                cin>>reg;
                if(reg==1){
                    cout<<"[*] Identificador de su Cliente (CODREG...)->"<<endl;
                    cin>>id;
                    cout<<"[*] Identificador de entrada(1-5)-> "<<endl;
                    cin>>entrada;
                    cout<<"[*] Identificador de concierto(1-5)-> "<<endl;
                    cin>>concierto;
                    c.setRegistrado(true);

                }
                else if(reg==0){
                    cout<<"[*] DNI del cliente ->"<<endl;
                    cin>>id;
                    cout<<"[*] Identificador de entrada(1-5)-> "<<endl;
                    cin>>entrada;
                    cout<<"[*] Identificador de concierto(1-5)-> "<<endl;
                    cin>>concierto;
                    c.setRegistrado(false);

                }
                else{
                    cout<<"[!] Introduce un numero dentro del rango establecido"<<endl;
                    cout<<"\n";
                    break;

                }
                c.setId(id);
                c.setTipoEntrada(entrada);
                c.setIdConcierto(concierto);
                c.setLlegada(rand()%60);
                if(c.isRegistrado()){
                    N1.encolar(c);
                    cout<<"[*] Cliente agregado correctamente a la cola de registrados"<<endl;
                }
                else{
                    N2.encolar(c);
                    cout<<"[*] Cliente agregado correctamente a la cola de no registrados"<<endl;
                }

                cout<<"\n";
                break;


            case 6:
                aux = N;
                cout<<"\n";
                cout<<"--------------------"<<endl;
                cout<<"| PILA DE CLIENTES |"<<endl;
                cout<<"--------------------"<<endl;
                aux.verPila();
                cout<<"\n";
                break;
            case 7:
                if(N.esVacia()){
                    cout<<"La PILA ya se encuentra vacia"<<endl;
                    cout<<"\n";
                }
                else{
                    while(!N.esVacia()){

                        N.desapilar();

                    }
                    cout<<"PILA borrada exitosamente"<<endl;
                    cout<<"\n";
                }
                break;
            case 8:

                cout<<"\n";
                cout<<"--------------------------------"<<endl;
                cout<<"| COLA DE CLIENTES REGISTRADOS |"<<endl;
                cout<<"--------------------------------"<<endl;
                N1.mostrarCola();
                cout<<"\n";
                break;


            case  9:
                cout<<"\n";
                cout<<"-----------------------------------"<<endl;
                cout<<"| COLA DE CLIENTES NO REGISTRADOS |"<<endl;
                cout<<"-----------------------------------"<<endl;
                N2.mostrarCola();
                cout<<"\n";
                break;

            case 10:
                cout<<"\n";
                cout<<"--------------------------------"<<endl;
                cout<<"|      BORRADO DE COLAS        |"<<endl;
                cout<<"--------------------------------"<<endl;
                cout<<"[*] Que cola deseas eliminar?"<<endl;
                cout<<"[1] Cola de Clientes registrados"<<endl;
                cout<<"[2] Cola de Clientes no registrados"<<endl;
                cin>>borrarCola;
                if(borrarCola==1){
                    while(!N1.esVacia()){
                        N1.desencolar();
                    }
                    cout<<"[*] Cola de clientes registrados borrada correctamente"<<endl;
                    cout<<"\n";
                }
                else if(borrarCola == 2){
                    while(!N2.esVacia()){
                        N2.desencolar();
                    }
                    cout<<"[*] Cola de clientes no registrados borrada correctamente"<<endl;
                    cout<<"\n";
                }else{

                    cout<<"[!] Introduce una opcion valida"<<endl;
                    cout<<"\n";
                }
                break;


            case 0:
                cout<<"[*] Gracias por usar nuestra plataforma!"<<endl;
                cout<<"[!] Saliendo..."<<endl;
                exit(0);


        }
    }

}
