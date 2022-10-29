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

/**
 @brief T.D.A MaxStack

 Se trata de una variación del tipo de dato abstracto Cola, concretamente de enteros.

 Así pues, se trata de una estructura capaz de almacenar en cada posición datos del tipo entero,
    y que además, permite conocer el valor máximo contenido en la estructura en cada momento.
 Si bien está implementada con pilas, solo permite introducir y borrar elementos por los dos extremos de la
    secuencia al igual que una cola normal, siguiendo así el modelo de secuencia FIFO (First In First Out).

 Para la implementación de este TDA utilizaremos un tipo de dato abstracto, "element",
    cuya especificación veremos a continuación.

 Para poder usar el TDA MaxQueue se debe incluir el fichero

  \#include <maxqueue.h>

  @author Gonzalo Martínez Piédrola
  @author Diego Ortega Sánchez
  @date Octubre 2022

 **/


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

    /**
     * @brief Constructor de copia.
     * @param origin Objeto que se copia.
     * @return El objeto copiado
     * @post origin no se modifica.
     */
    MaxQueue(const MaxQueue & origin); //Constructor de copia

    /**
     * @brief Destructor de la clase.
     * @post El objeto se borra de la memoria.
     */
    ~MaxQueue(); //Destructor

    /**
     * @brief Operador de copia.
     * @param origin Objeto que se copia
     * @post origin no se modifica
     * @return Devuelve un objeto igual que origin
     */
    MaxQueue & operator= (const MaxQueue & origin); //Operador de copia

    /**
     * @brief Comprueba si la cola está vacía.
     * @return Devuelve "true" si la cola está vacía, "false" en otro caso.
     */
    bool Empty() const; //Comprueba si la cola está vacía

    /**
     * @brief Cuenta el número de elementos que hay en la cola.
     * @return Devuelve el número de elementos de la cola.
     */
    int size () const; //Devuelve el número de elementos de la cola

    /**
     * @brief Intercambia los elementos de dos colas
     * @param p Cola que se intercambia con la cola a la que se aplica el método
     * @post Las dos colas se intercambian.
     */
    void swap (MaxQueue & p); //Intercambia los elementos de dos colas

    /**
     * @brief Copia los elementos de la cola en otra invirtiendo el orden
     * @param p Cola que se copia
     * @pre La cola no puede estar vacía.
     * @post La cola cuyos elementos se copian, no se modifica.
     */
    void invert (MaxQueue &p) const; //Copia los elementos de la cola en otra invirtiendo el orden

    /**
     * @return Devuelve el primer elemento añadido a la cola
     */
    element front () const;   //Devuelve el primer elemento añadido a la cola

    /**
     * @return Devuelve el último elemento añadido a la cola
     */
    element back () const; //Devuelve el último elemento añadido a la cola

    /**
     * @brief Añade un nuevo elemento a la cola
     * @param n El elemento que se añade
     * @post El tamaño de la cola aumenta en una unidad
     */
    void push (int n);  //Añade un nuevo elemento

    /**
     * @brief Borra el primer elemento añadido
     * @post El tamaño de la cola se reduce en una unidad
     */
    void pop (); //Borra el primer elemento añadido


};

#endif // _MAXQUEUE_H_
