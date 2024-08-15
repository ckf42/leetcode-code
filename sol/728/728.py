class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def isSelfDiv(num: int) -> bool:
            if 0 < num < 10:
                return True
            val = num
            while val != 0:
                d = val % 10
                if d == 0 or num % d != 0:
                    return False
                val //= 10
            return True

        return tuple(filter(isSelfDiv, range(left, right + 1)))
