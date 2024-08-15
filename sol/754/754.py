class Solution:
    def reachNumber(self, target: int) -> int:
        if target < 0:
            target = -target
        m = (int(sqrt(1 + 8 * target)) - 2) // 2
        q = -1
        while not (q >= 0 and (q & 3) == 0):
            m += 1
            q = m * (m + 1) - 2 * target
        return m
