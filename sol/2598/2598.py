class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        count = [0] * value
        for x in nums:
            count[x % value] += 1
        v = min(count)
        r = count.index(v)
        return v * value + r
