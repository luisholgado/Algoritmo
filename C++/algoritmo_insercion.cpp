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
// Función de ordenamiento insertion
void insercion(int array[], int n){
	int i, aux, k;
	for(i=1;i<n;i++){
		aux=array[i];
		k=i-1;
		while(k>=0&&aux<array[k]){
			array[k+1]=array[k];
			k=k-1;			
		}
		array[k+1]=aux;
	}	
}
// Método principal
int main()
{
	unsigned t0, t1;
    int **matriz=leerFichero("archivo100.txt");
    int *vector = devolverVector(matriz,filas);
    t0=clock();
    insercion(vector, filas);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo de ejecución: " << time << endl;
    cout << "El vector ordenado \n";
	//imprimeVector(vector);
}
