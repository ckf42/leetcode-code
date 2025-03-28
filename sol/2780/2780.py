class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        dom = 0
        vote = 0
        for x in nums:
            if vote == 0:
                dom = x
                vote = 1
            elif dom == x:
                vote += 1
            else:
                vote -= 1
        freq = nums.count(dom)
        count = 0
        for i, x in enumerate(nums):
            if x == dom:
                count += 1
            if freq * 2 - n > count * 2 - i - 1 > 0:
                return i
        return -1
