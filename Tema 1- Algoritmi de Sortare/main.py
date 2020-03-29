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


def primul(L):
    return L[0]


def mijloc(L):
    return L[len(L) // 2]


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
            HeapSort_imported(L)
        else:
            p = n // 2
            return interclasare(IntroSort(L[:p]), IntroSort(L[p:]))


def InsSort(arr, begin, end):
    global start, time_limit
    for i in range(begin + 1, end + 1):
        if timer() - start < time_limit:
            elem = arr[i]
            j = i - 1
            while j >= begin and elem < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = elem
    return arr


def ShellSort(L):
    gaps = [0]
    gap = 3
    while gap < len(L):
        gaps.append(gap)
        gap = (gap + 1) * 2 - 1
    for gap in gaps:
        arr = InsSort(L, gap, len(L) - 1)
    return arr


def tim_merge(L, st, mid, dr):  # Interclasam 2 runs sortate din acelasi array
    if mid == end:
        return L
    first = L[st:mid + 1]  # Separam cele 2 runs
    last = L[mid + 1:dr + 1]
    len1 = len(first)
    len2 = len(last)
    i = 0
    j = 0
    ind = st
    while i < len1 and j < len2:  # Interclasare
        if first[i] < last[j]:
            L[ind] = first[i]
            i += 1
        else:
            L[ind] = last[j]
            j += 1
        ind += 1
    while i < len1:
        L[ind] = first[i]
        i += 1
        ind += 1
    while j < len2:
        L[ind] = last[j]
        j += 1
        ind += 1
    return L


def TimSort(L, run_size=128):
    n = len(L)
    for st in range(0, n, run_size):  # Sortam fiecare run folosind InsertionSort
        dr = min(st + run_size - 1, n - 1)
        L = InsSort(L, st, dr)

    curr_size = run_size
    while curr_size < n:  # Interclasam runs
        for st in range(0, n, curr_size * 2):
            mid = min([n - 1, st + curr_size - 1])
            dr = min([n - 1, mid + curr_size])
            L = tim_merge(L, st, mid, dr)
        curr_size *= 2
    return L


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


def SelectionSort(L):
    global start, time_limit
    for i in range(len(L)):
        if timer() - start < time_limit:
            a = i
            for j in range(i + 1, len(L)):
                if L[a] > L[j]:
                    a = j
            L[i], L[a] = L[a], L[i]
    return L


with open("E:\PyCharmProjects\\teste.in") as f:
    nr_test = 0
    time_limit = 1  # Pt multe nr ar trebui data limita mai mare
    sortari = [CountingSort, HeapSort_imported, HeapSort, RadixSort, MergeSort, BubbleSort, InsertionSort, TimSort,
               IntroSort, SelectionSort, ShellSort]
    modes = ["RANDOM", "SORTATE", "APROAPE SORTATE","ORDONATE DESCRESCATOR"]
    for test in f:
        test = test.split()
        N = int(test[0])
        MAX = int(test[1])
        mode = int(test[2])
        if mode == 0:
            A = [randint(1, MAX) for iter in range(N)]
        elif mode == 2:
            A = [randint(1, MAX) for iter in range(N)]
            for iter in range(N // 4):
                a = randint(1, N - 1)
                b = randint(1, N - 1)
                A[a], A[b] = A[b], A[a]
        elif mode == 1:
            A = [iter for iter in range(N)]
        else:
            A = [iter for iter in range(N - 1, -1, -1)]
        nr_test += 1
        min_time = [9999, "Default"]
        print(f"--- TESTUL NR {nr_test}  - {N} NR {modes[mode]} CU MAXIMUL DE {MAX} ---")

        for sortare in sortari:
            B = [x for x in A]
            start = timer()
            B = sortare(B)
            end = timer()
            time = round((end - start) * 1000, 3)
            if (isSorted(B)):
                print(f"{sortare.__name__} - Status: OK - Time: {time} ms")
                if time < min_time[0]:
                    min_time = [time, sortare.__name__]
            else:
                if (time > time_limit):
                    print(f"{sortare.__name__} - Status: FAILED - Reason: OUT OF TIME")
                else:
                    print(f"{sortare.__name__} - Status: FAILED - Reason: Array not sorted")

        # QuickSort Primul Element
        B = [x for x in A]
        start = timer()
        B = QuickSort(B, 0, len(B) - 1, primul)
        end = timer()
        time = round((end - start) * 1000, 3)
        if time < min_time[0]:
            min_time = [time, "QuickSort Primul Element"]
        if (isSorted(B)):
            print(f"QuickSort Primul Element - Status: OK - Time: {time} ms")
        else:
            print(f"QuickSort Primul Element - Status: FAILED")

        # QuickSort Element Mijloc
        B = [x for x in A]
        start = timer()
        B = QuickSort(B, 0, len(B) - 1, mijloc)
        end = timer()
        time = round((end - start) * 1000, 3)
        if time < min_time[0]:
            min_time = [time, "QuickSort Element Mijloc"]
        if (isSorted(B)):
            print(f"QuickSort Element Mijloc - Status: OK - Time: {time} ms")
        else:
            print(f"QuickSort Element Mijloc - Status: FAILED")

        # QuickSort Random
        B = [x for x in A]
        start = timer()
        B = QuickSort(B, 0, len(B) - 1, choice)
        end = timer()
        time = round((end - start) * 1000, 3)
        if time < min_time[0]:
            min_time = [time, "QuickSort Random"]
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
        if time < min_time[0]:
            min_time = [time, "QuickSort Mediana Medianelor"]
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
            f"Timpul minim pt sortările implementate dat de {min_time[1]}: {min_time[0]} ms vs {time_sorted} ms al sortării din limbaj. "
            f"Sortarea din limbaj a fost cu {round(min_time[0] - time_sorted, 2)} ms mai rapidă, adică {round(min_time[0] / time_sorted * 100, 2)}%.")
        print()
