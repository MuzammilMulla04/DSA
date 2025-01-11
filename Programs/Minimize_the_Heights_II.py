""" GeeksForGeeks """ 
""" GeeksForGeeks """
class Solution:
    def getMinDiff(self, arr,k):
        n= len(arr)
        if n == 1:
            return 0
        
        arr.sort()
        smallest= arr[0] + k
        largest= arr[n-1] - k
        
        diff= arr[n-1] - arr[0]
        for i in range(len(arr)-1):
            min_height= min(smallest, arr[i+1] - k)
            max_height= max(largest, arr[i] + k)
            
            if min_height < 0:
                continue
            
            diff= min(diff, max_height - min_height)
        
        return diff
