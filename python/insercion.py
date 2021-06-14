# -*- coding: utf-8 -*-
"""
Created on Sun Jun 13 20:43:25 2021

@author: Luis
"""
import time
archivo=open('E:/2021/UNSA/Semestre I/Algoritmos/Practica/python/archivo100.txt','r')
#archivo.read()
lista=[]
#for x in archivo.readlines():
def crear_lista(file):
    for count, value in enumerate(file):
        if(count!=0):
            lista.append(int(value))
def cerrar_ficher(file):
    file.close()
def imprimir(l):
    for x in l:
        print(x)
def insercion(arr,n):
    for i in range(1, n, 1):
        aux=arr[i]
        k=i-1
        while(k>=0 and aux<arr[k]):
            arr[k+1]=arr[k]
            k=k-1
        arr[k+1]=aux
        
crear_lista(archivo)
cerrar_ficher(archivo)      
imprimir(lista)
print("-----------------------------------------------------------------------")
print("Luego de ordenar")
print("-----------------------------------------------------------------------")
inicio = float(time.time())
insercion(lista, 100)
fin = float(time.time())
print(fin-inicio)
imprimir(lista)