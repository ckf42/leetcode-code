class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        st = []
        for i, x in enumerate(nums):
            if len(st) == 0 or nums[st[-1]] > x:
                st.append(i)
        res = 0
        for j in range(n - 1, -1, -1):
            while len(st) != 0 and nums[st[-1]] <= nums[j]:
                res = max(res, j - st.pop())
        return res
