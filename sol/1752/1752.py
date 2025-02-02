class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        seenDrop = False
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                if seenDrop:
                    return False
                seenDrop = True
        if seenDrop and nums[n - 1] > nums[0]:
            return False
        return True
