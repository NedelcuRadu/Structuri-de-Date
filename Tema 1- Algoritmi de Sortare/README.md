# Tema 1 - Algoritmi de sortare pt numere naturale 

### Algoritmi implementati:
* Bubble Sort
* Insertion Sort
* Heap Sort - manual / folosind heapq
* Merge Sort
* QuickSort - mediana medianelor / random / element static 
* RadixSort 
* Counting Sort
* Selection Sort
* Intro Sort - conform pseudocodului de pe Wikipedia
* Shell Sort - gaps de forma 2*k+1
* TimSort - run_size 

_Format teste (pe cate o linie): N MAX MODE_  
* N - cate numere sunt
* MAX - maximul numerelor
* MODE - felul in care sunt generate ( 0 - RANDOM, 1 - SORTATE, 2 - APROAPE SORTATE, 3 - DESCRESCATOR)


### Concluzii: 
* Sortarea din limbaj este de cel putin 2 ori mai rapida decat orice alta implementare, pe orice set de date.

###### Excluzand sortarea din limbaj:

* Datorita librariei heapq, HeapSort este cea mai rapida sortare pt numere mari, daca MAX este relativ mic, CountingSort castiga
* Pt numere putine, InsertionSort este cea mai rapida varianta.
