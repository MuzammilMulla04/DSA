class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        freq= {i:0 for i in range(10)}
        for digit in digits:
            if digit not in freq.keys():
                freq[digit]= 1
            else:
                freq[digit] += 1
        
        ans= list()

        for num in range(100, 1000, 1):
            hundreds= int(num / 100)
            tens= int(num / 10) % 10
            units= num % 10

            if units % 2 != 0:
                continue

            freq[hundreds] -= 1
            if freq[hundreds] >= 0:
                freq[tens] -= 1

                if freq[tens] >= 0:
                    freq[units] -= 1

                    if freq[units] >= 0:
                        ans.append(num)
                    freq[units] += 1
                freq[tens] += 1
            freq[hundreds] += 1

        return ans
