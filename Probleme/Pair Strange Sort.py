# Parameter array is an array where each element
# is an array of 2 elements
# The function should return an array of arrays

def pair_strange_sort(array):
    dict = {}
    rez = []
    for x in array:
        if tuple(x) not in dict:
            dict[tuple(x)] = 1
            x.append(1)
            rez.append(x)
        else:
            dict[tuple(x)]+=1
            x.append(dict[tuple(x)])
            rez.append(x)
    rez.sort(key= lambda x: (x[0],x[2],x[1]))
    return rez
###
n = int(input())
array = []
for i in range(n):
    array.append(list(map(int, input().split(' '))))
sorted_array = pair_strange_sort(array)
for element in sorted_array:
    print(str(element[0]) + " " +  str(element[1]))
