# Parameters a1 and a2 are two arrays of integers
# The function should return an array of integers
from collections import Counter
def array_intersection(a1, a2):
    counter1 = Counter(a1)
    counter2 = Counter(a2)
    rez = []
    for item in counter1.items():
        if item[0] in counter2:
           for i in range(min(item[1],counter2[item[0]])):
               rez.append(item[0])
    print (len(rez))
    return rez
###
n, m = map(int, input().split(' '))
a1 = list(map(int, input().split(' ')))
a2 = list(map(int, input().split(' ')))
intersection = array_intersection(a1, a2)
print(' '.join(map(str, intersection)))
