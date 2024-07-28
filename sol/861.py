class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        nums = [
            sum(row[j] * (1 << (n - 1 - j)) for j in range(n))
            for row in grid
        ]
        lead = 1 << (n - 1)
        flip = (1 << n) - 1
        for i in range(m):
            if nums[i] & lead == 0:
                nums[i] ^= flip
        lead = 1
        for j in range(n):
            if sum((x & lead) // lead for x in nums) <= m // 2:
                for i in range(m):
                    nums[i] ^= lead
            lead <<= 1
        return sum(nums)
