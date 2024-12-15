from collections import deque

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        stDec = deque()
        stInc = deque()
        e = 0
        for s in range(n):
            while e < n:
                while len(stDec) != 0 and nums[stDec[-1]] <= nums[e]:
                    stDec.pop()
                stDec.append(e)
                while len(stInc) != 0 and nums[stInc[-1]] >= nums[e]:
                    stInc.pop()
                stInc.append(e)
                if nums[stDec[0]] - nums[stInc[0]] > 2:
                    break
                e += 1
            res += e - s
            if stDec[0] == s:
                stDec.popleft()
            if stInc[0] == s:
                stInc.popleft()
        return res
