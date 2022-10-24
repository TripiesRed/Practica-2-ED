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
MaxQueue::MaxQueue() {}

// Constructor de copia
MaxQueue::MaxQueue(const MaxQueue &origin) {
    memoria=origin.memoria;
}

// Destructor
MaxQueue::~MaxQueue() {}

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

// Método que copia los elementos de la cola en otra cola invirtiendo el orden
void MaxQueue::invert(MaxQueue &p) const {
    MaxQueue paste(*this);
    for (int i = 0; i < size(); i++){
        p.memoria.push(paste.memoria.top());
        paste.memoria.pop();
    }
}

// Método que devuelve el último elemento añadido a la cola
element MaxQueue::back() const {
    return memoria.top();
}

// Método que devuelve el primer elemento añadido a la cola
element MaxQueue::front() const {
    MaxQueue copy;

    invert(copy);

    return copy.back();
}

// Método que añade un nuevo elemento a la cola
void MaxQueue::push(int n) {

    //Ajustamos parámetro max del nuevo elemento
    element newelement;
    newelement.value = n;

    if(Empty())
        newelement.max = n;


    else{
        if(back().max >= newelement.value)
            newelement.max = back().max;

        else{
            newelement.max = n;
            MaxQueue copy, paste;

            invert(copy);
            copy.memoria.top().max=n;
            copy.invert(paste);
            *this=paste;
        }

    }

    memoria.push(newelement); //Añadimos el nuevo elemento

}

// Método que elimina el primer elemento añadido a la cola
void MaxQueue::pop() {
    MaxQueue copy, paste;

    invert(copy); //Invertimos orden
    copy.memoria.pop();

    if(copy.back().max != back().max)
        copy.memoria.top().max=back().max;
    copy.invert(paste);

    *this=paste;
}

