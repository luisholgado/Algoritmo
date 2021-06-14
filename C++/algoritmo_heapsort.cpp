// C++ program for implementation of Heap Sort
// Adaptado de : https://www.geeksforgeeks.org/heap-sort/
// https://www.delftstack.com/es/tutorial/algorithm/heap-sort/#:~:text=La%20funci%C3%B3n%20Heapify()%20es,de%20tiempo%20sea%20tambi%C3%A9n%20nlogn%20.
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <ctime>
using namespace std;
int filas = 0;
int cols = 0;
// Funcion que lee el fichero como matriz de numeros
int** leerFichero(char *fileName) {
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	fgets(linea, 79, fp);
	char *token = strtok(linea, " ");//10 6
	filas = atoi(token);
	token = strtok(NULL, " ");
	cols = atoi(token);
	int **matriz = new int*[filas];
	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[cols];
		fgets(linea,79, fp);
		token = strtok(linea, "");
		matriz[i][0] = atoi(token);
		for (int j = 1; j < cols; j++) {
			token = strtok(NULL, "");
			matriz[i][j] = atoi(token);
		}
	}
	fclose(fp);
	return matriz;
}
// funcion que obtiene una fila de la matriz
int *devolverVector(int **m, int f){
	int* v = new int[filas];
	for (int i=0; i<f; i++){
		v[i] = m[i][0];
	}        
    return v;
}
// impresion de la matriz
void imprimeVector(int *vector) {

	for (int i = 0; i < filas; i++) {	
            cout<<vector[i]<<"\n";
	}
	cout<<endl;
}
// funcion que crea el montículo
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
//Funcion heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
         // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
// Método principal
int main()
{
	unsigned t0, t1;
 	int **matriz=leerFichero("archivo100000.txt");
    int *vector = devolverVector(matriz,filas);
    //imprimeVector(vector);
    t0=clock();
    heapSort(vector, filas);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo de ejecución: " << time << endl;
    //cout << "El vector ordenado \n";
	//imprimeVector(vector);
}




