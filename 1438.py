from collections import deque

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        qmin, qmax = deque(), deque()
        res = 0
        l = 0
        for r, x in enumerate(nums):
            while len(qmin) != 0 and qmin[-1] > x:
                qmin.pop()
            qmin.append(x)
            while len(qmax) != 0 and qmax[-1] < x:
                qmax.pop()
            qmax.append(x)
            while qmax[0] - qmin[0] > limit:
                if qmax[0] == nums[l]:
                    qmax.popleft()
                if qmin[0] == nums[l]:
                    qmin.popleft()
                l += 1
            res = max(res, r - l + 1)
        return res
