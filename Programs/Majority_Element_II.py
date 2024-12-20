""" LeetCode """
# 2. Boyer-Moore’s Voting Algorithm
class Solution:
    def majorityElement(self, nums: list[int]) -> list[int]:
        e1, e2, c1, c2= float('-inf'), float('-inf'), 0, 0
        for num in nums:
            if num == e1:
                c1 += 1
            elif num == e2:
                c2 += 1
            elif c1 == 0:
                e1= num
                c1= 1
            elif c2 == 0:
                e2= num
                c2= 1
            else:
                c1 -= 1
                c2 -= 1

        c1= c2= 0
        for num in nums:
            c1 += num == e1
            c2 += num == e2

        n= len(nums)
        ans= []
        if c1 > n//3:
            ans.append(e1)
        if c2 > n//3 and e1 != e2:
            ans.append(e2)
        
        return sorted(ans)

""" CodingNinjas """
# 2. Boyer-Moore’s Voting Algorithm
def majorityElementII(nums):
	e1, e2, c1, c2= float('-inf'), float('-inf'), 0, 0
	for num in nums:
		if num == e1:
			c1 += 1
		elif num == e2:
			c2 += 1
		elif c1 == 0:
			e1= num
			c1= 1
		elif c2 == 0:
			e2= num
			c2= 1
		else:
			c1 -= 1
			c2 -= 1

	c1= c2= 0
	for num in nums:
		c1 += num == e1
		c2 += num == e2

	n= len(nums)
	ans= []
	if c1 > n//3:
		ans.append(e1)
	if c2 > n//3 and e1 != e2:
		ans.append(e2)
	
	return sorted(ans)

""" GeeksForGeeks """
# 2. Boyer-Moore’s Voting Algorithm
class Solution:
    def findMajority(self, nums):
        e1, e2, c1, c2= float('-inf'), float('-inf'), 0, 0
        for num in nums:
            if num == e1:
                c1 += 1
            elif num == e2:
                c2 += 1
            elif c1 == 0:
                e1= num
                c1= 1
            elif c2 == 0:
                e2= num
                c2= 1
            else:
                c1 -= 1
                c2 -= 1

        c1= c2= 0
        for num in nums:
            c1 += num == e1
            c2 += num == e2

        n= len(nums)
        ans= []
        if c1 > n//3:
            ans.append(e1)
        if c2 > n//3 and e1 != e2:
            ans.append(e2)
        
        return sorted(ans)
