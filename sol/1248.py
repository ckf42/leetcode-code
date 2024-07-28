from collections import deque

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        res = 0
        q = deque((-1,))
        for i, x in enumerate(nums):
            if x & 1 == 0:
                continue
            if len(q) == k + 1:
                l = q.popleft()
                res += (q[0] - l) * (i - q[-1])
            q.append(i)
        if len(q) == k + 1:
            res += (q[1] - q[0]) * (len(nums) - q[-1])
        return res
