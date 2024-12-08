""" CodingNinjas """
def findSecondLargest(arr):
    max1= float('-inf')
    max2= float('-inf')

    for num in arr:
        if num > max1:
            max2= max1
            max1= num
        elif max1 > num and num > max2:
            max2= num
    
    if max2 == float('-inf'):
        return -1
    else:
        return max2

""" GeeksForGeeks """
class Solution:
    def getSecondLargest(self, arr):
        max1= -1
        max2= -1

        for num in arr:
            if num > max1:
                max2= max1
                max1= num
            elif max1 > num and num > max2:
                max2= num
        
        return max2
