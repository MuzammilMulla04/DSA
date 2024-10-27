from os import *
from sys import *
from collections import *
from math import *

def reverseArray(arr, m):
    i= m+1
    j= len(arr) - 1

    while i<j:
        arr[i], arr[j]= arr[j], arr[i]

        i += 1
        j -= 1
        
    return arr
