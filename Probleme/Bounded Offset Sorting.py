# Parameter array is an array of integers
# Parameter m is an integer
# The function should return an array of integers
from heapq import heapify,heappop,heappushpop
def bounded_offset_sorting(array, m):
    rez = []
    if m>1:
        i=m
        heap = array[:m]
        heapify(heap)
        while i < len(array):
            rez.append(heappushpop(heap,array[i]))
            i+=1
        while len(heap)>0:
            rez.append(heappop(heap))
    else:
        rez = sorted(array)
    return rez
###
n, m = map(int, input().split(' '))
array = list(map(int, input().split(' ')))
sorted_array = bounded_offset_sorting(array, m)
print(' '.join(map(str, sorted_array)))
