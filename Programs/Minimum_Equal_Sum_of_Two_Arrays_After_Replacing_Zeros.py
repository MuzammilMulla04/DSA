class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1= sum2= 0
        zero1= zero2= 0

        for num in nums1:
            if num == 0:
                zero1 += 1
            else:
                sum1 += num
        for num in nums2:
            if num == 0:
                zero2 += 1
            else:
                sum2 += num
        
        if sum1 + zero1 > sum2 + zero2:
            if zero2 == 0:
                return -1
        elif sum1 + zero1 < sum2 + zero2:
            if zero1 == 0:
                return -1
        
        return max(sum1 + zero1, sum2 + zero2)
