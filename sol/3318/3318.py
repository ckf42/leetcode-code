import heapq as hq

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        res = [0] * (n - k + 1)
        freq = dict()
        for z in nums[:k - 1]:
            freq[z] = freq.get(z, 0) + 1
        for i in range(n - k + 1):
            z = nums[i + k - 1]
            freq[z] = freq.get(z, 0) + 1
            h = []
            for z, f in freq.items():
                if f == 0:
                    continue
                hq.heappush(h, (f, z))
                if len(h) > x:
                    hq.heappop(h)
            res[i] = sum(z * f for f, z in h)
            freq[nums[i]] -= 1
        return res
