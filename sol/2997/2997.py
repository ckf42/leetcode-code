class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        for x in nums:
            k ^= x
        # fastest method still appears to be this
        return bin(k).count('1')

