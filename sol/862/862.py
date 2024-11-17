from collections import deque

class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        q = deque()
        q.append(-1)
        res = n + 1
        for i in range(n):
            prefix[i] = prefix[i - 1] + nums[i]
            while len(q) != 0 and prefix[q[0]] <= prefix[i] - k:
                res = min(res, i - q.popleft())
            while len(q) != 0 and prefix[q[-1]] >= prefix[i]:
                q.pop()
            q.append(i)
        return -1 if res > n else res
