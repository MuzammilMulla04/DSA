""" CodingNinjas """
# Use Sorting [O(nlog(n)), O(n)]
def findDuplicate(arr: list, n: int):
    arr.sort()      # Can use any sort
    i= 0
    for j in range(1, n):
        if arr[i] == arr[j]:
            return arr[i]
        else:
            i += 1

# use List [O(n), O(n)]
def findDuplicate(arr: list, n: int):
    frequency= [0] * n
    for num in arr:
        frequency[num] += 1
    
    for num, freq in enumerate(frequency):
        if freq > 1:
            return num
    return -1

# Use Dict [O(n), O(n)]
def findDuplicate(arr: list, n: int):
    freq= {}
    for num in arr:
        if num in freq.keys():
            freq[num] += 1
        else:
            freq[num]= 1
    
    for num, value in freq.items():
        if value > 1:
            return num
    return -1

# Use Counter [O(n), O(n)]
from collections import Counter
def findDuplicate(arr: list, n: int):
    freq= Counter(arr)
    return freq.most_common(1)[0][0]
    
# Use Floyd's Cycle Detection [O(n), O(1)]
def findDuplicate(arr: list, n: int):
    slow, fast = arr[0], arr[arr[0]]
    while slow != fast:
        slow = arr[slow]
        fast = arr[arr[fast]]
    fast = 0
    while fast != slow:
        fast = arr[fast]
        slow = arr[slow]
    return slow

""" LeetCode """
class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        slow, fast = nums[0], nums[nums[0]]
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]
        fast = 0
        while fast != slow:
            fast = nums[fast]
            slow = nums[slow]
        return slow
