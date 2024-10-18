class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        n = len(s)
        l = -1
        r = -1
        idx = n - 1
        for i in range(n - 2, -1, -1):
            if s[i] > s[idx]:
                idx = i
            elif s[i] != s[idx]:
                l = i
                r = idx
        if l != -1:
            s[l], s[r] = s[r], s[l]
        return int(''.join(s))
