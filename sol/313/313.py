import heapq as hq

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        if n == 1:
            return 1
        np = len(primes)
        memo = [-1] * n
        memo[0] = 1
        chainIdx = [0] * np
        h = [(p, i) for i, p in enumerate(primes)]
        hq.heapify(h)
        w = 1
        while w < n:
            x, pIdx = hq.heappop(h)
            if x != memo[w - 1]:
                memo[w] = x
                w += 1
            chainIdx[pIdx] += 1
            hq.heappush(h, (memo[chainIdx[pIdx]] * primes[pIdx], pIdx))
        return memo[n - 1]
