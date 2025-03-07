class Solution:
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
        rg = [True for _ in range(left, right + 1, 2)]
        n = len(rg)
        m = int(right ** 0.5)
        for divisor in range(3, m + 1, 2):
            k = max(3, (left - 1) // divisor + 1)
            if (k & 1) == 0:
                k += 1
            for val in range(divisor * k, right + 1, divisor * 2):
                rg[(val - left) // 2] = False
        lptr = 0
        while lptr < n - 1 and not rg[lptr]:
            lptr += 1
        if lptr == n - 1:
            return [-1, -1]
        res = [-1, -1]
        while lptr < n - 1:
            rptr = lptr + 1
            while rptr < n and not rg[rptr]:
                rptr += 1
            if rptr == n:
                break
            if res[0] == -1 or (rptr - lptr) * 2 < res[1] - res[0]:
                res = [left + lptr * 2, left + rptr * 2]
            if rptr - lptr == 1:
                break
            lptr = rptr
        return res
