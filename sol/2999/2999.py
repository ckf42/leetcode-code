class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        mask = 10 ** len(s)
        sint = int(s)
        if start % mask > sint:
            start += mask
        start //= mask
        if finish % mask < sint:
            finish -= mask
        finish //= mask
        if finish < start:
            return 0
        def count(n: int) -> int:
            ptr = 1
            subChoice = 1
            res = 0
            while ptr * 10 <= n:
                ptr *= 10
                subChoice *= limit + 1
            while ptr != 0:
                digit = n // ptr
                if digit > limit:
                    res += subChoice * (limit + 1)
                    break
                res += subChoice * (digit + (1 if ptr == 1 else 0))
                n %= ptr
                ptr //= 10
                subChoice //= limit + 1
            return res
        return count(finish) - (0 if start == 0 else count(start - 1))
