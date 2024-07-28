import heapq as hq

class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        largest = hq.nlargest(2, nums)
        smallest = hq.nsmallest(2, nums)
        return largest[0] * largest[1] - smallest[0] * smallest[1]
