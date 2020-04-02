def merge(A, B):
    i = 0
    j = 0
    C = []
    while (i < len(A) and j < len(B)):
        if (A[i] < B[j]):
            C.append(A[i])
            i += 1
        else:
            C.append(B[j])
            j += 1
    C.extend(A[i:])
    C.extend(B[j:])
    return C


def down(heap, nod):
    st = nod * 2 + 1
    dr = nod * 2 + 2
    smallest = nod
    if st < len(heap) and heap[smallest] > heap[st]:
        smallest = st
    if dr < len(heap) and heap[smallest] > heap[dr]:
        smallest = dr
    if smallest != nod:
        heap[smallest], heap[nod] = heap[nod], heap[smallest]
        down(heap, smallest)


def up(heap, nod):
    key = heap[nod]
    while (nod > 0 and key < heap[nod // 2]):
        heap[nod] = heap[nod // 2]
        nod = nod // 2
    heap[nod] = key

def insert_heap(heap,nod):
    heap.append(nod)
    up(heap,len(heap)-1)

def build_heap(L):
    for i in range(len(L) // 2, -1, -1):
        down(L, i)


def remove_min(heap):
    heap.remove(heap[0])
    down(heap, 0)


def get_min(heap):
    return heap[0]


with open("liste.in") as f: # Pe fiecare linie cate un sir ordonat crescator
    A = []
    for linie in f:
        L = [int(x) for x in linie.split()]
        A.append(L)
print(A)
heap = []

for iter in range(len(A)):
    heap.append((len(A[iter]), iter))  # Lungimea si a cata lista e

build_heap(heap)

while len(heap) > 1:
    list_1 = get_min(heap)
    remove_min(heap)
    list_2 = get_min(heap)
    remove_min(heap)
    A[list_1[1]] = merge(A[list_1[1]], A[list_2[1]])
    insert_heap(heap,(len(A[list_1[1]]), list_1[1]))
    print(heap)

print(A[list_1[1]])
