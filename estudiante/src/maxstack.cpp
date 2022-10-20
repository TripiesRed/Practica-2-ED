/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <queue>

#include <maxstack.h>

using namespace std;

/****************************************
        FUNCIONES PÚBLICAS
*****************************************/

// Constructor por defecto
MaxStack::MaxStack() {}

// Destructor
MaxStack::~MaxStack() {}

// Constructor de copia
MaxStack::MaxStack(const MaxStack &origin) {
    memoria=origin.memoria;
}

// Operador de copia
MaxStack &MaxStack::operator=(const MaxStack &origin) {
    memoria=origin.memoria;
    return *this;
}

// Método que comprueba si la pila está vacía
bool MaxStack::Empty() const {
    return memoria.empty();
}

// Método que devuelve la longitud de la pila
int MaxStack::size() const {
    return memoria.size();
}

// Método que intercambia los datos de dos pilas
void MaxStack::swap(MaxStack &p) {
    memoria.swap(p.memoria);
}

// Método que devuelve el último elemento añadido a la pila
element MaxStack::top() const {
    return memoria.back();
}

// Método que añade un nuevo elemento a la pila
void MaxStack::push(int n) {

    //Ajustamos parámetro max del nuevo elemento
    element newelement;
    newelement.value = n;

    if(Empty())
        newelement.max = n;


    else{
        if(top().max <= newelement.value)
            newelement.max = newelement.value;

        else
            newelement.max = top().max;
    }

    memoria.push(newelement); //Añadimos el nuevo elemento

}

// Método que elimina el último elemento añadido a la pila
void MaxStack::pop() {
    MaxStack copy;

    for (int i = 0; i < size(); i++){
        copy.push(memoria.front().value);
        memoria.pop();
    }

    *this=copy;
}








