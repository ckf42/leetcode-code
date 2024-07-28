class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        s = set(nums)
        while len(s) != 0:
            l = 1
            x = s.pop()
            y = x
            while y + 1 in s:
                l += 1
                y += 1
                s.remove(y)
            y = x
            while y - 1 in s:
                l += 1
                y -= 1
                s.remove(y)
            res = max(res, l)
        return res
