class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        edges = [[] for _ in range(n)]
        for j in range(1, n):
            for i in range(j):
                if nums[j] % nums[i] == 0:
                    edges[j].append(i)
        optimalNext = [-1] * n
        optimalLen = [1] * n
        for i in range(n):
            selection = max(edges[i], key=lambda idx: optimalLen[idx], default=-1)
            if selection != -1:
                optimalNext[i] = selection
                optimalLen[i] = optimalLen[selection] + 1
        res = []
        ptr = max(range(n), key=lambda idx: optimalLen[idx])
        while ptr != -1:
            res.append(nums[ptr])
            ptr = optimalNext[ptr]
        return res

