from random import randint, choice
from timeit import default_timer as timer
from heapq import heapify, heappop
from math import log, floor


def min_heapify(L, node, size):
    st = node * 2 + 1
    dr = node * 2 + 2
    smallest = node
    if dr < size and L[dr] < L[smallest]:
        smallest = dr
    if st < size and L[st] < L[smallest]:
        smallest = st
    if smallest != node:
        L[smallest], L[node] = L[node], L[smallest]
        min_heapify(L, smallest, size)


def make_heap(L, size):
    for i in range(size // 2 + 1, -1, -1):
        min_heapify(L, i, size)


def HeapSort(L):
    global start, time_limit
    rez = []
    n = len(L)
    make_heap(L, n)
    i = 0
    while (n):
        if timer() - start < time_limit:
            rez.append(L[0])
            i += 1
            n -= 1
            make_heap(L[i:], n)
        else:
            return [0, -1]
    return rez


def pivot_mediana(A):
    if len(A) <= 5:
        try:
            return sorted(A)[len(A) // 2]
        except IndexError:
            return 0
    subliste = [sorted(A[i:i + 5]) for i in range(0, len(A), 5)]
    mediane = [sl[len(sl) // 2] for sl in subliste]
    return pivot_mediana(mediane)


def interclasare(lst, ldr):
    i = j = 0
    rez = []
    while i < len(lst) and j < len(ldr):
        if lst[i] < ldr[j]:
            rez.append(lst[i])
            i += 1
        else:
            rez.append(ldr[j])
            j += 1
    rez.extend(ldr[j:])
    rez.extend(lst[i:])
    return rez


def MergeSort(L):
    if len(L) <= 1:
        return L
    else:
        return interclasare(MergeSort(L[len(L) // 2:]), MergeSort(L[:len(L) // 2]))


def BubbleSort(L):
    global start, time_limit
    for i in range(len(L)):
        if timer() - start < time_limit:
            for j in range(0, len(L) - 1 - i):
                if L[j] > L[j + 1]:
                    L[j], L[j + 1] = L[j + 1], L[j]
        else:
            return [0, -1]
    return L


def isSorted(L):
    for i in range(len(L) - 1):
        if L[i + 1] < L[i]:
            # print(f"Nu e bine la {L[i]},{L[i + 1]}")
            return False
    return True


def CountingSort(L):
    maxim = max(L)
    if max(L) > 1e7:
        print("Maximul prea mare pt CountingSort")
        return [0, -1]
    else:
        A = []
        rez = []
        for i in range(maxim + 1):
            A.append(0)
        for nr in L:
            A[nr] += 1
        for i in range(maxim + 1):
            for j in range(A[i]):
                rez.append(i)
        return rez


def HeapSort_imported(L):
    rez = []
    heapify(L)
    while len(L):
        rez.append(heappop(L))
    return rez


def QuickSort(L, inf, sup, fct_pivot=pivot_mediana):
    i = inf
    j = sup
    pivot = fct_pivot(L[inf:sup])
    while i <= j:
        while i < sup and L[i] < pivot:
            i += 1
        while L[j] > pivot and j >= inf:
            j -= 1
        if i <= j:
            aux = L[i]
            L[i] = L[j]
            L[j] = aux
            i += 1
            j -= 1
    if i < sup:
        QuickSort(L, i, sup)
    if j > inf:
        QuickSort(L, inf, j)
    return L


def InsertionSort(L):
    global start, time_limit
    for i in range(0, len(L)):
        if timer() - start < time_limit:
            elem = L[i]
            j = i - 1
            while j >= 0 and elem < L[j]:
                L[j + 1] = L[j]
                j -= 1
            L[j + 1] = elem
        else:
            return [0, -1]
    return L


def IntroSort(L):
    n = len(L)
    if n <= 1:
        return L
    else:
        if round(log(n, 10) * 10) == 0:
            L = HeapSort_imported(L)
        else:
            p = n // 2
            # p= partition(L)
            return interclasare(IntroSort(L[:p]), IntroSort(L[p:]))


def RadixSort(A, baza=10):
    placement = 1  # Asta pare sa fie cea mai buna combinatie - 0,12 ms pe 100 nr 10^6
    nrcif = floor(
        log(max(A), baza)) + 1  # E mai rapid sa gasesc nr maxim de cifre decat sa merg cu un bool si if de fiecare data
    for i in range(nrcif):
        buckets = [[] for iter in range(
            baza)]  # E mai rapid sa le reinitializez cu [] decat sa le dau clear sau list()  - testat cu TimeIt
        for i in A:
            tmp = i // placement
            buckets[tmp % baza].append(i)
        a = 0
        for iter in range(baza):
            for i in buckets[iter]:
                A[a] = i
                a += 1
        # Urmatoarea "cifra"
        placement *= baza
    return A


with open("teste.in") as f:
    nr_test = 0
    time_limit = 1
    for test in f:
        sortari = [CountingSort, HeapSort_imported, HeapSort, RadixSort, MergeSort, BubbleSort, InsertionSort]
        test = test.split()
        N = int(test[0])
        MAX = int(test[1])
        A = [randint(1, MAX) for iter in range(N)]
        nr_test += 1
        min = [9999, "Default"]
        print(f"--- TESTUL NR {nr_test} - {N} NR CU MAXIMUL DE {MAX} ---")

        for sortare in sortari:
            B = [x for x in A]
            start = timer()
            B = sortare(B)
            end = timer()
            time = round((end - start) * 1000, 3)
            if (isSorted(B)):
                print(f"{sortare.__name__} - Status: OK - Time: {time} ms")
                if time < min[0]:
                    min = [time, sortare.__name__]
            else:
                if (time > time_limit):
                    print(f"{sortare.__name__} - Status: FAILED - Reason: OUT OF TIME")
                else:
                    print(f"{sortare.__name__} - Status: FAILED - Reason: Array not sorted")

        # QuickSort Random
        B = [x for x in A]
        start = timer()
        B = QuickSort(B, 0, len(B) - 1, choice)
        end = timer()
        time = round((end - start) * 1000, 3)
        if time < min[0]:
            min = [time, "QuickSort Random"]
        if (isSorted(B)):
            print(f"QuickSort Random - Status: OK - Time: {time} ms")
        else:
            print(f"QuickSort Random - Status: FAILED")

        # QuickSort Mediana medianelor
        B = [x for x in A]
        start = timer()
        B = QuickSort(B, 0, len(A) - 1, pivot_mediana)
        end = timer()
        time = round((end - start) * 1000, 3)
        if time < min[0]:
            min = [time, "QuickSort Mediana Medianelor"]
        if (isSorted(B)):
            print(f"QuickSort Mediana Medianelor - Status: OK - Time: {time} ms")
        else:
            print(f"QuickSort Mediana Medianelor - Status: FAILED")

        # Sortarea din limbaj
        start = timer()
        B = sorted(A)
        end = timer()
        time_sorted = round((end - start) * 1000, 3)
        if (isSorted(B)):
            print(f"Sortarea din limbaj - Status: OK - Time: {time_sorted} ms")
        else:
            print(f"Sortarea din limbaj - Status: FAILED - Time: {time_sorted} ms")

        print(
            f"Timpul minim pt sortările implementate dat de {min[1]}: {min[0]} ms vs {time_sorted} ms al sortării din limbaj. "
            f"Sortarea din limbaj a fost cu {round(min[0] - time_sorted, 2)} ms mai rapidă, adică {round(min[0] / time_sorted * 100, 2)}%.")
        print()
