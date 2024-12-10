""" LeetCode """
class Solution:
    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end]= nums[end], nums[start]
            start += 1
            end -= 1

    def rotate(self, nums: list[int], k: int) -> None:
        n= len(nums)
        k %= n

        k= n-k

        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, n-1)
        self.reverse(nums, 0, n-1)


""" CodingNinjas """
def rotateArray(arr, k):
    n = len(arr)
    temp = [0] * n

    for i in range(n):
        temp[(i + (n - k)) % n] = arr[i]

    return temp


""" GeeksForGeeks """
class Solution:
    def reverse(self, arr, start, end):
        while start < end:
            arr[start], arr[end]= arr[end], arr[start]
            start += 1
            end -= 1

    def rotateArr(self, arr, d):
        n= len(arr)
        d %= n

        self.reverse(arr, 0, d-1)
        self.reverse(arr, d, n-1)
        self.reverse(arr, 0, n-1)
