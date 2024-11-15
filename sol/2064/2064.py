class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        m = len(quantities)
        quantities.sort(reverse=True)
        def required(k):
            res = 0
            for i, x in enumerate(quantities):
                if x <= k:
                    return res + m - i
                res += (x + k - 1) // k
            return res
        s = 1
        e = quantities[0]
        while s < e:
            k = (s + e) // 2
            if required(k) > n:
                s = k + 1
            else:
                e = k
        return s
