""" LeetCode """

class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        s1= set(nums1)
        s2= set(nums2)

        return list(s1 & s2)
    
""" codingNinjas """

from collections import Counter

def intersections(arr1, n, arr2, m) :
    c1= Counter(arr1)
    c2= Counter(arr2)

    for num in arr1:
        if c1[num] > 0 and c2[num] > 0:
            print(num, end= ' ')
            c1[num] -= 1
            c2[num] -= 1  
