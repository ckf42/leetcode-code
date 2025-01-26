class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        res = [0] * n
        sortedIdx = sorted(range(n), key=lambda idx: nums[idx])
        s = 0
        while s < n:
            e = s + 1
            while e < n and nums[sortedIdx[e]] - nums[sortedIdx[e - 1]] <= limit:
                e += 1
            gpIdx = sorted(sortedIdx[s:e])
            sortedVal = sorted((nums[idx] for idx in gpIdx))
            for i, idx in enumerate(gpIdx):
                res[idx] = sortedVal[i]
            s = e
        return res
