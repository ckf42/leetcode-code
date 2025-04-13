class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        fact = [1] * 11
        for i in range(2, 11):
            fact[i] = fact[i - 1] * i
        seen = set()
        res = 0
        l = (n + 1) // 2 - 1
        for prefix in range(10 ** l, 10 ** (l + 1)):
            pal = prefix
            if n & 1:
                prefix //= 10
            while prefix != 0:
                pal = pal * 10 + prefix % 10
                prefix //= 10
            t = ''.join(sorted(str(pal)))
            if pal % k != 0 or t in seen:
                continue
            seen.add(t)
            count = [0] * 10
            while pal != 0:
                count[pal % 10] += 1
                pal //= 10
            perm = fact[n - 1] * (n - count[0])
            for f in count:
                if f > 10:
                    print(f, count)
                perm //= fact[f]
            res += perm
        return res
