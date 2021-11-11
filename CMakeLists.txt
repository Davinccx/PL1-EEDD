cmake_minimum_required(VERSION 3.20)
project(Practica)

set(CMAKE_CXX_STANDARD 14)

add_executable(Practica main.cpp Cliente.cpp Cliente.h Gestor.cpp Gestor.h NodoCola.cpp NodoCola.h ColaCliente.cpp ColaCliente.h NodoPila.cpp NodoPila.h Pila.cpp Pila.h)
