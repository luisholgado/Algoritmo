# -*- coding: utf-8 -*-
"""
Created on Sun Jun 13 17:42:08 2021
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
def heapify(arr,n,i):
    parent=i
    lChild=2*i+1
    rChild=2*i+2
    if(lChild<n and arr[lChild]>arr[parent]):
        parent=lChild
    if(rChild<n and arr[rChild]>arr[parent]):
        parent=rChild
    if(parent!=i):
        arr[i],arr[parent] = arr[parent],arr[i] 
        heapify(arr, n, parent)
def heapsort(arr, n):
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i] 
        heapify(arr, i, 0)
crear_lista(archivo)
cerrar_ficher(archivo)      
imprimir(lista)
print("-----------------------------------------------------------------------")
print("Luego de ordenar")
print("-----------------------------------------------------------------------")
inicio = float(time.time())
heapsort(lista, 100)
fin = float(time.time())
print(fin-inicio)
imprimir(lista)






