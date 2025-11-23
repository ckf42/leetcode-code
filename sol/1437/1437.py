class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -(k + 1)
        for i, x in enumerate(nums):
            if x == 0:
                continue
            if i - prev <= k:
                return False
            prev = i
        return True
