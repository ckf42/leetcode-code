class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        small = []
        large = []
        i = 1
        while i ** 2 <= n:
            q, r = divmod(n, i)
            if r == 0:
                small.append(i)
                if i != q:
                    large.append(q)
                if len(small) == k:
                    return i
            i += 1
        if (idx := len(small) + len(large) - k) >= 0:
            return large[idx]
        else:
            return -1
