/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#include <cstring>
#include <cassert>
#include <iostream>
#include <stack>

#include <maxqueue.h>

using namespace std;

/****************************************
        FUNCIONES PÚBLICAS
*****************************************/

// Constructor por defecto
MaxQueue::MaxQueue(){};

// Constructor de copia
MaxQueue::MaxQueue(const MaxQueue &origin) {
    memoria=origin.memoria;
}

// Operador de copia
MaxQueue &MaxQueue::operator=(const MaxQueue &origin) {
    memoria=origin.memoria;
    return *this;
}

// Método que comprueba si la cola está vacía
bool MaxQueue::Empty() const {
    return memoria.empty();
}

// Método que devuelve la longitud de la cola
int MaxQueue::size() const {
    return memoria.size();
}

// Método que intercambia los datos de dos colas
void MaxQueue::swap(MaxQueue &p) {
    memoria.swap(p.memoria);
}

// Método que devuelve el primer elemento añadido a la cola
element MaxQueue::front() const {
    return memoria.top();
}

// Método que añade un nuevo elemento a la cola
void MaxQueue::push(int n) {

    element newelement;
    stack<element> aux;
    newelement.value = n;
    newelement.max = n;

    while(!Empty()){
        aux.push(memoria.top());
        memoria.pop();
    }

    memoria.push(newelement);

    while(!aux.empty()){
        memoria.push(aux.top());
        if(memoria.top().max < newelement.max)
            memoria.top().max = newelement.max;
        aux.pop();
    }

}

// Método que elimina el primer elemento añadido a la cola
void MaxQueue::pop() {
    memoria.pop();
}

