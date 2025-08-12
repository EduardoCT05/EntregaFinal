#pragma once

#include <iostream>
#include <forward_list> // uso listas enlazadas para el encadenamiento (chaining)
#include <string>
using namespace std;

// Tabla hash genérica con encadenamiento.
// Idea: tengo un arreglo de listas, y cada lista guarda los elementos que caen
// en el mismo índice (colisiones) según la función hash.
template <typename T>
class HashTableChaining
{
    // Aquí guardo los datos: es un arreglo de listas (forward_list) de tamaño N.
    // Cada posición del arreglo es un "bucket" y adentro hay una lista de elementos.
    forward_list<T>* data;
    unsigned int arraySize; // tamaño del arreglo (número de buckets)
    // Nota: "unsigned" = sin signo, o sea no admite valores negativos.

    ...
public:
    // Constructor: recibe el tamaño y reserva memoria para N listas.
    HashTableChaining(unsigned int size)
    {
        // pido memoria para N forward_list<T>
        data = new forward_list<T>[size];
        arraySize = size;
    }

    // Destructor: libero la memoria pedida para evitar fugas (memory leak).
    virtual ~HashTableChaining()
    {
        delete[] data;
    }

    // Función hash: mapea la llave (key) a un índice válido [0, arraySize).
    // Ojo: aquí asumo que T se puede usar con %, por ejemplo enteros.
    // Si T fuera string, tocaría hacer otra función hash.
    // "la convierte en un entero" (como dice tu comentario original).
    int HashFunction(T key)
    {
        return key % arraySize;
    }

    // Métodos básicos: insertar, quitar, buscar e imprimir.
    // Los marco virtual para poder hacer una clase hija (HashSet) que haga override.
    virtual void Add(T element)
    {
        // Calculo a qué bucket cae este elemento
        int index = HashFunction(element);
        // Inserto al inicio de la lista del bucket (push_front es O(1))
        data[index].push_front(element);

    }

    ...
        // Eliminar un elemento (si existe). Si no está, lanzo excepción.
        virtual void Remove(T element)
    {
        int index = HashFunction(element);
        forward_list<T>& listAtIndex = data[index];

        // Recorro la lista del bucket
        for (auto i : listAtIndex) // este for-each itera toda la forward_list
        {
            if (i == element)
            {
                // Si lo encuentro, lo quito y ya
                listAtIndex.remove(i);
                return;
            }
        }

        // Si llegué aquí es porque no estaba
        throw runtime_error("no element " + to_string(element) + " in this hash table.");

    }

    // contains: función de búsqueda. Regresa true si sí está, false si no.
    bool Contains(T element)
    {
        int index = HashFunction(element);
        forward_list<T>& listAtIndex = data[index];

        for (auto i : listAtIndex)
        {
            if (i == element)
            {
                // Si lo encuentro, ya no hay que seguir
                return true;
            }
        }
        return false;
    }

    // Print: recorre todos los buckets e imprime lo que haya en cada uno.
    void Print()
    {
        for (unsigned int i = 0; i < arraySize; ++i)
        {
            cout << "[" << i << "]: ";
            // Recorro la lista de este bucket y voy imprimiendo
            for (auto j : data[i])
                cout << j << ", ";

            cout << endl;
        }
    }

};

void HashTableChainingExample();
