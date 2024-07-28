import heapq as hq

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        largest = hq.nlargest(4, nums)
        smallest = hq.nlargest(4, nums, key=lambda x: -x)
        return min(
            largest[3] - smallest[0],
            largest[2] - smallest[1],
            largest[1] - smallest[2],
            largest[0] - smallest[3])
