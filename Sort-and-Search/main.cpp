#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

#include "Fraccion.h"

// Clears the command line in Linux, Apple and Windows
void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

// SWAPS the elements of a list when given the
// parameters like this "&lista[i], &lista[j]""
template <class T>
void swap(T *xp, T *yp) 
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Merges the sorted arrays.
template <class T>
void merge(vector<T> &lista, int l, int m, int r, int &count)
{
	int leftSize = m-l+1, rightSize = r-m;

	vector<T> L(leftSize);
	vector<T> R(rightSize);

	for(int i = 0; i < leftSize; i++)
	{
		L[i] = lista[l+i];
	}

	for(int j = 0; j < rightSize; j++)
	{
		R[j] = lista[m+j+1];
	}

	int i = 0, j = 0;
	int k;

	for (k = l; k <= r && i < leftSize && j < rightSize; k++)
	{
		if(L[i] <= R[j])
		{
			lista[k] = L[i];
			i++;
		}
		else
		{
			lista[k] = R[j];
			j++;
		}
	}

	for (i = i; i < leftSize; ++i)
	{
		lista[k] = L[i];
		k++;
	}

	for (j = i; j < rightSize; j++)
	{
		lista[k] = R[j];
		k++;
	}
}

// SELECTION SORT ALGORITHM
template<class T>
vector<T> intercambioVector(vector<T> lista, int n, int size, int &count) 
{
    for (int i = n; i < size; i++) 
	{
        for (int j= i + 1; j < size; j++) 
		{
            if (lista[i] > lista[j]) 
			{
                swap(&lista[i], &lista[j]);
				count++;
            }
        }
    }
    return lista;
}

// BUBBLE SORT ALGORITHM
template <class T>
vector<T> burbujaVector(vector <T> lista, int n, int size, int &count) 
{
    for (int i = n; i < size - 1; i++) 
	{ 
        for (int j = 0; j < size - i - 1; j++)
		{  
			if (lista[j] > lista[j+1])  
			{
				swap(&lista[j], &lista[j+1]);
				count++;
			}
		}
	}
    return lista;
}

// MERGE SORT ALGORITHM
template <class T>
void mergeReal(vector <T> &lista, int l, int r, int &count)
{
	if (l < r )
	{
		int m = (l+r)/2;
		mergeReal(lista, l, m, count);
		mergeReal(lista, m+1, r, count);
		merge(lista, l, m, r, count);
	}
}

// Holds merge function since I need to use pointers in this code, but the rest of algorithms don't.
template <class T>
vector<T> mergeVector(vector <T> lista,  int l, int r, int &count) 
{
	mergeReal(lista, l, r, count);
	return lista;
}

// PRINTS THE VECTOR or "List" YOU WANT
template <class T>
void imprimirVector(vector <T> lista) 
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;
}

// CREATES A RANDOM LIST OF INTEGERS
void creaListaINT(vector<int> &lista, int cantidad)
{
    lista.clear();
    for (int i=0; i<cantidad; i++) 
	{
        lista.push_back(rand() % 100 + 1);
    }
}

// CREATES A RANDOM LIST OF CHARACTERS
void creaListaCHAR(vector<char> &lista, int cantidad)
{
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) 
	{
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

// CREATES A RANDOM LIST OF FRACTIONS
void creaListaFO(vector<Fraccion> &lista, int cantidad) 
{
    lista.clear();
    int numerador, denominador;
    for (int i=0;i<cantidad;i++) 
	{
        cout << "Teclea el numerador: " << endl;
        cin >> numerador;
        cout << "Teclea el denominador: " << endl;
        cin >> denominador;
        lista.push_back(Fraccion(numerador,denominador));
    }
}

// CREATES A RANDOM LIST OF STRINGS
void creaListaSTR(vector<string> &lista, int cantidad) 
{
    lista.clear();
    string valor;
    for (int i=0;i<cantidad;i++) 
	{
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

template<class T>
vector<T> temporizador(vector<T> lista, int n, int size, int &count, vector<T> (*sort_search_func) (vector<T> lista, int n, int size, int &count)) 
{
	count = 0;
	auto start = chrono::steady_clock::now();
    
	lista = (*sort_search_func)(lista, n, size, count);

	auto end = chrono::steady_clock::now();
	auto diff = end - start;

	cout << "Tiempo  : " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
	cout << "Pasos   : " << count << "       steps \n"<< endl;

	return lista;
}

// Text that belongs to the submenu after an option is selected.
template <class T>
void submenuText(vector<T> &lista)
{
	cout << "\nSin ordenar: \n" << endl;
	imprimirVector(lista);
	cout << "\n";
	cout << "Ordenado: " << endl;
}

// MENU to use the SORTS/SEARCH ALGORITHM
template <class T>
void submenu(vector<T> lista) 
{
	char op;
	int count;
	while ( op != 'z') 
	{
		cout << endl;
		cout << "Sub-Menu" << endl;
		cout << "a) Orden por Intercambio" << endl;
		cout << "b) Orden por Burbujua" << endl;
		cout << "c) Orden por Merge   " << endl;
		cout << "z) Regresar" << endl;
		cout << endl << "Teclea una opción:" << endl;
		cin >> op;

		switch (op) 
		{
			case 'a':
				submenuText(lista);
				imprimirVector(temporizador(lista, 0, lista.size(),count, &intercambioVector));
				break;

			case 'b':
				submenuText(lista);
				imprimirVector(temporizador(lista, 0, lista.size(), count, &burbujaVector));
				break;

			case 'c':
				submenuText(lista);
				imprimirVector(temporizador(lista, 0, lista.size()-1, count, &mergeVector));
				break;

			break;
		}
	}
}

int main()
{
    srand(time(NULL));
	int cant;
	char op, tipo;
	
    vector<int> listaINT;
    vector<char> listaCHAR;
	vector<Fraccion> listaFO;
    vector<string> listaSTR;

    while (tipo != 'z') 
	{
		Clear();
		cout << endl;
		cout << "Menu Principal" << endl;
		cout << "e) Enteros random" << endl;
		cout << "f) Fraccion escritas por ti" << endl;
		cout << "c) Carácteres random" << endl;
		cout << "s) Palabras escritas por ti" << endl;
		cout << "z) Salir" << endl;

		cout << endl << "Selecciona el tipo de datos a usar: " << endl;
		cin >> tipo;

		cout << endl << "Selecciona la cantidad de datos a usar: " << endl;
		cin >> cant;

		switch (tipo) 
		{
			case 'e':
				creaListaINT(listaINT,cant);
				submenu(listaINT);
				break;
			case 'f':
				creaListaFO(listaFO,cant);
				submenu(listaFO);
				break;
			case 'c':
				creaListaCHAR(listaCHAR,cant);
				submenu(listaCHAR);
				break;
			case 's':
				creaListaSTR(listaSTR,cant);
				submenu(listaSTR);
				break;
			break;
		}
	}
}