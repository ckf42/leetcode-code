import heapq as hq

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        diff = [0] * (n + 1)
        cumsum = 0
        q = len(queries)
        queries.sort(key=lambda itv: itv[0])
        h = []
        qptr = 0
        count = 0
        for i in range(n):
            cumsum += diff[i]
            while qptr < q and queries[qptr][0] <= i:
                hq.heappush(h, -queries[qptr][1])
                qptr += 1
            while len(h) != 0 and cumsum < nums[i]:
                r = -hq.heappop(h)
                if r >= i:
                    cumsum += 1
                    diff[r + 1] -= 1
                    count += 1
            if cumsum < nums[i]:
                return -1
        return q - count
