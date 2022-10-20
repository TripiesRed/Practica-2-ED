/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

using namespace std;

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_

#include <iostream>
#include <queue>

/**
 @brief T.D.A MaxStack

 Se trata de una variación del tipo de dato abstracto Pila, concretamente de enteros.

 Así pues, se trata de una estructura capaz de almacenar en cada posición datos del tipo entero,
    y que además, nos permitirá conocer el valor máximo contenido en la estructura en cada momento.
 Al igual que una pila normal, solo permite introducir y borrar elementos por un extremo de la
    secuencia denominado tope, siguiendo así el modelo de secuencia LIFO (Last In First Out).

 Para la implementación de este TDA utilizaremos un tipo de dato abstracto, "element",
    cuya especificación veremos a continuación.

 Para poder usar el TDA MaxStack se debe incluir el fichero

  \#include <maxstack.h>

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

class MaxStack {

private:

    /**
     @brief Dato miembro de tipo cola que actúa como contenedor lineal de la memoria de
        la pila de tipo MaxStack.

     La "queue" memoria simula el almacenamiento interno que tendría la pila MaxStack, permitiéndonos
         guardar los datos de tipo "element" y trabajar con ellos con los métodos propios de la
         clase "queue" con el fin de desarrollar métodos propios para la clase MaxStack.
     **/

    queue<element> memoria;

public:

    /**
      * @brief Constructor por defecto.
      * @post Genera una pila con 0 elementos.
      * @return MaxStack, el objeto imagen creado.
      **/
    MaxStack(); //Constructor por defecto

    MaxStack(const MaxStack & origin); //Constructor de copia

    ~MaxStack(); //Destructor

    MaxStack & operator= (const MaxStack & origin); //Operador de copia

    bool Empty() const; //Comprueba si la pila está vacía

    int size () const; //Devuelve el número de elementos de la pila

    void swap (MaxStack & p); //Intercambia los elementos de dos pilas

    element top () const;   //Devuelve el último elemento añadido a la pila

    void push (int n);  //Añade un nuevo elemento

    void pop (); //Borra el último elemento añadido


};

#endif // _MAXSTACK_H_




