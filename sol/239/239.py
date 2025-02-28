from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = [0] * (n - k + 1)
        q = deque()
        for i in range(k):
            while len(q) != 0 and q[-1] < nums[i]:
                q.pop()
            q.append(nums[i])
        res[0] = q[0]
        for i in range(k, n):
            while len(q) != 0 and q[-1] < nums[i]:
                q.pop()
            q.append(nums[i])
            if nums[i - k] == q[0]:
                q.popleft()
            res[i - k + 1] = q[0]
        return res
