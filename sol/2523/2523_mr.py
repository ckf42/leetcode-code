class Solution:
    @staticmethod
    def detMillerRabin(n: int) -> bool:
        d = n - 1
        s = 0
        while (d & 1) == 0:
            s += 1
            d >>= 1
        for a in (2, 3):
            x = pow(a, d, n)
            for _ in range(s):
                y = pow(x, 2, n)
                if y == 1 and x != 1 and x != n - 1:
                    return False
                x = y
            if x != 1:
                return False
        return True
    def closestPrimes(self, left: int, right: int) -> List[int]:
        if left == right:
            return [-1, -1]
        if left <= 2:
            return [2, 3] if right >= 3 else [-1, -1]
        if (left & 1) == 0:
            left += 1
        if (right & 1) == 0:
            right -= 1
        if right - left <= 1:
            return [-1, -1]
        res = [-1, -1]
        l = left
        while l < right and not self.detMillerRabin(l):
            l += 2
        while l < right:
            r = l + 2
            while r <= right and not self.detMillerRabin(r):
                r += 2
            if r > right:
                break
            if res[0] == -1 or r - l < res[1] - res[0]:
                res = [l, r]
            if r - l == 2:
                break
            l = r
        return res
