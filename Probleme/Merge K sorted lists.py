import heapq

def lungime(A):
    for i in range(len(A)):
        if len(A[i])>0:
            return 1
    return 0

with open("data.in") as f:
    A = []
    for linie in f:
        A.append([int(x) for x in linie.split()])
    print(A)

B = []
rez = []
for i in range(len(A)):
    B.append((A[i][0], i))
heapq.heapify(B)
while lungime(A) > 0:
    if len(B) > 0:
        minim = B[0]
        A[minim[1]] = A[minim[1]][1:]
        rez.append(heapq.heappop(B)[0])
    try:
        heapq.heappush(B, (A[minim[1]][0], minim[1]))
    except:
        pass
print(rez)
