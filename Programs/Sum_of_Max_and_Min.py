# CodingNinjas
# 1. Use sys
from sys import maxsize
def sumOfMaxMin(arr):
    minValue, maxValue= maxsize, -maxsize-1
    for num in arr:
        minValue= num if num < minValue else minValue
        maxValue= num if num > maxValue else maxValue
    return minValue + maxValue

# 2. Use ∞
def sumOfMaxMin(arr):
    minValue, maxValue= int('inf'), int('-inf')
    for num in arr:
        minValue= num if num < minValue else minValue
        maxValue= num if num > maxValue else maxValue
    return minValue + maxValue

#  3. Use built-in Functions
def sumOfMaxMin(arr):
    return min(arr) + max(arr)