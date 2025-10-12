class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        power.sort()
        vals = []
        counts = []
        prev = power[0]
        count = 1
        for p in power[1:]:
            if p != prev:
                vals.append(prev)
                counts.append(count)
                count = 0
                prev = p
            count += 1
        vals.append(prev)
        counts.append(count)
        m = len(vals)
        memo = [0] * m
        memo[0] = vals[0] * counts[0]
        for i in range(1, m):
            p = vals[i] * counts[i]
            memo[i] = max(p, memo[i - 1])
            if vals[i - 1] < vals[i] - 2:
                memo[i] = max(memo[i], memo[i - 1] + p)
            elif i >= 2 and vals[i - 2] < vals[i] - 2:
                memo[i] = max(memo[i], memo[i - 2] + p)
            elif i >= 3:
                memo[i] = max(memo[i], memo[i - 3] + p)
        return memo[-1]
