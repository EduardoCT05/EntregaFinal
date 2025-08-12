
// Librerías básicas
#include <iostream>
#include <string>

// Requisito del profe: en el main debo incluir estos headers
#include "BinarySearchTree.h"     // Árbol binario de búsqueda (template en el .h)
#include "HashTableChaining.h"    // Hash con encadenamiento (para cumplir el include)

// Opcional pero útil para la evidencia: probar el HashSet que hereda de la Hash
#include "HashSet.h"

using namespace std;

// Esta función crea un BST<int>, inserta datos, hace búsquedas, recorridos
// y borra elementos en los tres casos (hoja, un hijo, dos hijos).
void EjecutarPruebaBST()
{
	cout << "         PRUEBA: BinarySearchTree       " << endl;

	BinarySearchTree<int> tree; // creo mi arbolito vacío

	// Inserciones (incluyo un duplicado para ver que se va a la izquierda)
	cout << "=== Inserciones ===" << endl;
	tree.Add(10);
	tree.Add(5);
	tree.Add(15);
	tree.Add(5);   // duplicado, segun la impl va al subárbol izquierdo
	tree.Add(12);
	tree.Add(18);
	tree.Add(3);
	tree.Add(7);

	cout << "InOrder (recursivo, deberia salir ordenado):" << endl;
	tree.InOrderWithRecursive();

	// Búsquedas (una que existe y otra que no)
	cout << "Busquedas " << endl;
	cout << "Search(7): " << (tree.Search(7) ? "Encontrado" : "No esta") << endl;
	cout << "Search(100): " << (tree.Search(100) ? "Encontrado" : "No esta") << endl;

	// Post-order (iterativo con dos pilas)
	cout << " PostOrderIterative (dos pilas) " << endl;
	tree.PostOrderIterative();

	// Versión post-order con una sola pila (para tener variante distinta)
	cout << " PostOrderIterativeOneStack (una pila) " << endl;
	tree.PostOrderIterativeOneStack();

	// Borrados:
	// 1) Borrar una hoja (por ejemplo 3)
	cout << " Delete: hoja (3) " << endl;
	tree.Delete(3);
	tree.InOrderWithRecursive();

	// 2) Borrar un nodo con un solo hijo (por ejemplo 12 o 18 según cómo quedó)
	cout << "Delete: un solo hijo (12)" << endl;
	tree.Delete(12);
	tree.InOrderWithRecursive();

	// 3) Borrar un nodo con dos hijos (por ejemplo 10, la raiz)
	cout << "Delete: dos hijos (10)" << endl;
	tree.Delete(10);
	tree.InOrderWithRecursive();

	// Limpieza total en post-order (L-R-N) para probar la función nueva
	cout << "ClearPostOrderRecursive (borra todo)" << endl;
	tree.ClearPostOrderRecursive();
	cout << "(Arbol vacio) InOrder:" << endl;
	tree.InOrderWithRecursive();

	cout << "        FIN PRUEBA: BinarySearchTree     " << endl;
}


// Esta función demuestra que el HashSet no mete repetidos.
// También imprime, busca, y prueba el remove + excepción si no existe.
void EjecutarPrueb;