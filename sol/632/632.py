import heapq as hq
from collections import deque

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        ptrs = [1] * k
        arrCount = [0] * k
        totCount = 0
        h = [(nums[i][0], i) for i in range(k)]
        hq.heapify(h)
        q = deque()
        minWindow = [-10 ** 5, 10 ** 5]
        while len(h) != 0:
            v, arridx = hq.heappop(h)
            if ptrs[arridx] != len(nums[arridx]):
                hq.heappush(h, (nums[arridx][ptrs[arridx]], arridx))
                ptrs[arridx] += 1
            q.append((v, arridx))
            arrCount[arridx] += 1
            if arrCount[arridx] == 1:
                totCount += 1
            while len(q) != 0 and totCount == k and arrCount[q[0][1]] != 1:
                arrCount[q.popleft()[1]] -= 1
            if totCount == k \
                    and q[-1][0] - q[0][0] < minWindow[1] - minWindow[0]:
                minWindow = [q[0][0], q[-1][0]]
        return minWindow
