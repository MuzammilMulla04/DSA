from collections import Counter

#  Set
class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        freq= Counter(arr)
        freqSet= set(freq.values())

        return len(freqSet) == len(freq)