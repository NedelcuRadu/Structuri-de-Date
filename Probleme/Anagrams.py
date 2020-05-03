
# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

def anagrame(a,b): # Numaram literele din fiecare cuvant
    len1 = len(a)
    len2 = len(b)
    if len1!=len2:
        return False
    count1 = {}
    count2 = {}
    for litera in a:
        if litera in count1:
            count1[litera] +=1
        else:
            count1[litera] = 1
    for litera in b:
        if litera in count2:
            count2[litera] +=1
        else:
            count2[litera] = 1
    if count2 == count1:
        return True
    return False
    
# Facem un dictionar avand cheia un cuvant si valoarea nr de anagrame
a = get_number()
max = 1
dictionar = {}
for i in range(a):  
    word = get_word()
    found = False
    for x in dictionar:
       if(anagrame(x,word)):
            dictionar[x]+=1
            if dictionar[x] > max:
                max = dictionar[x]
            found = True
    if not found:
        dictionar[word]=1
print(max)
    
   
   
