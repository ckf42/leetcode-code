class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        indices = tuple(i for i, v in enumerate(nums) if v == key)
        l = len(indices)
        ptr = -1
        res = []
        for i in range(n):
            while ptr < l - 1 and indices[ptr + 1] <= i + k:
                ptr += 1
            if ptr != -1 and i - indices[ptr] <= k:
                res.append(i)
        return res
