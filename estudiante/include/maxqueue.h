/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

using namespace std;

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_

#include <iostream>
#include <stack>

// Aquí falta la especificación de MaxQueue

/**
 * @brief T.D.A que almacena un valor entero y el valor máximo de la pila en el momento
 *  en el que es añadido.
 */
struct element {
    int value; // Valor del elemento
    int max;   // Valor máximo en la estructura
};

class MaxQueue{

private:

    stack<element> memoria;


public:

    /**
      * @brief Constructor por defecto.
      * @post Genera una pila con 0 elementos.
      * @return MaxQueue, el objeto imagen creado.
      **/
    MaxQueue(); //Constructor por defecto

    MaxQueue(const MaxQueue & origin); //Constructor de copia

    ~MaxQueue(); //Destructor

    MaxQueue & operator= (const MaxQueue & origin); //Operador de copia

    bool Empty() const; //Comprueba si la cola está vacía

    int size () const; //Devuelve el número de elementos de la cola

    void swap (MaxQueue & p); //Intercambia los elementos de dos colas

    /**
     * @brief
     * @param p
     * @pre La cola no puede estar vacía
     * @post La cola cuyos elementos vamos a copiar, no se modifica
     */
    void invert (MaxQueue &p) const; //Copia los elementos de la cola en otra invirtiendo el orden

    element front () const;   //Devuelve el primer elemento añadido a la cola

    element back () const; //Devuelve el último elemento añadido a la cola

    void push (int n);  //Añade un nuevo elemento

    void pop (); //Borra el primer elemento añadido


};

#endif // _MAXQUEUE_H_
