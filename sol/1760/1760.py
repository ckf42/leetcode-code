class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        e = max(nums) + 1
        s = 1
        while s < e:
            m = (s + e) // 2
            if sum((x - 1) // m for x in nums) <= maxOperations:
                e = m
            else:
                s = m + 1
        return s
