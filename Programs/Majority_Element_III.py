from collections import Counter

""" CodingNinjas """
def countTheNumber(arr, n, k):
    freq= Counter(arr)
    ans= [key for key, value in freq.items() if value >= n/k]
    return ans