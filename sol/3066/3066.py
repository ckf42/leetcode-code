import heapq as hq

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        hq.heapify(nums)
        res = 0
        while nums[0] < k:
            x = hq.heappop(nums)
            hq.heapreplace(nums, x * 2 + nums[0])
            res += 1
        return res

