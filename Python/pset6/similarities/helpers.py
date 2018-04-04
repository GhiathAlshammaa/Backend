from collections import OrderedDict
from nltk.tokenize import sent_tokenize

def lines(a, b):

    # Input
    line1 = a.splitlines()
    line2 = b.splitlines()

    #Operation (converting the strings into lines)
    x= list()
    # counter for the new list
    counter = 0
    # every element of the line1 will check all the elment of the line2
    for i in line1:
          if i in line2:
            x.insert(counter,i)
            counter +=1
    set(x)
    return x


def sentences(a, b):

    x= list()

    #operation (converting the strings into sentences)
    sentence1 = sent_tokenize(a)
    sentence2 = sent_tokenize(b)

    # counter for the new list
    counter = 0
    # every element of the line1 will check all the elment of the line2
    for i in sentence1:
          if i in sentence2:
            x.insert(counter,i)
            counter +=1
    x = list(OrderedDict.fromkeys(x))
    set(x)
    return x


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    # TODO
    # Input
    length = n
    result = [0 for x in range(len(a)+len(b))]

    #operation (converting the strings into substring)
    a = convert_string_to_substring (a,length)
    b = convert_string_to_substring (b,length)

    # Comparison operation
    result = compare_list(a,b)

    # Output
    result = list(OrderedDict.fromkeys(result))

    return result

# my functions
def convert_string_to_substring (a,length):
    # new list
    z = [0 for x in range(len(a))]
    counter = 0

    # this the operation which will convert the string to substring
    for i in range(len(a)):
      if length == len(a)+1:
        break
      else:
        #print ("(A): ", a[i:length])
        z[i] = a[i:length]
        #print (i,length)
        length +=1
        counter +=1

    # loop to cancel the empty elments
    x=remove_empty_elements(counter,z)

    return x


def remove_empty_elements (c,z):
    x=[0 for x in range(c)]
    for i in range(c):
        if z[i] != 0:
            x[i] = z[i]

    return x


def compare_list(a,b):
    # Every element of the line1 will check all the elment of the line2
    z = [0 for x in range(len(a)+len(b))]
    counter = 0

    for i in range(len(a)):
       for j in range(len(b)):
          if a[i] == b[j]:
            z[counter] = a[i]
            counter +=1

    z= remove_empty_elements (counter,z)
    return z

#def cmp(a, b):
#    return (a > b) - (a < b)




