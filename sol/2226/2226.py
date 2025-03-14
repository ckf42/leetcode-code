class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        total = sum(candies)
        if total < k:
            return 0
        if total == k:
            return 1
        s = 1
        e = total // k + 1
        while s < e:
            m = (s + e) // 2
            if sum(x // m for x in candies) >= k:
                s = m + 1
            else:
                e = m
        return e - 1
