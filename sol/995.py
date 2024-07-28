class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        flipCount = 0
        for i in range(n):
            if i >= k and nums[i - k] == -1:
                flipCount -= 1
            if (flipCount & 1) == nums[i]:
                if i >= n - k + 1:
                    return -1
                res += 1
                flipCount += 1
                nums[i] = -1
        return res
