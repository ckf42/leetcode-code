from collections import defaultdict

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        parents = list(range(n))
        size = [1] * n

        def get(x):
            while parents[x] != x:
                x, parents[x] = parents[x], parents[parents[x]]
            return x

        def union(i, j):
            i, j = get(i), get(j)
            if i == j:
                return
            if size[i] < size[j]:
                i, j = j, i
            parents[j] = i
            size[i] += size[j]

        primes = [2, 3, 5, 7]
        firstOccur = defaultdict(lambda: -1)
        for i, x in enumerate(nums):
            while primes[-1] ** 2 < x:
                candidate = primes[-1] + 2
                while any(candidate % p == 0 for p in primes):
                    candidate += 2
                primes.append(candidate)
            for p in primes:
                if p > x:
                    break
                if x % p == 0:
                    if firstOccur[p] == -1:
                        firstOccur[p] = i
                    else:
                        union(firstOccur[p], i)
                    while x % p == 0:
                        x //= p
            if x != 1:
                if firstOccur[x] == -1:
                    firstOccur[x] = i
                else:
                    union(firstOccur[x], i)
        return size[get(0)] == n
