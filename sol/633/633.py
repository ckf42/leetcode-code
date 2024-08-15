class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(c ** (1 / 2))
        while a <= b:
            d = a * a + b * b
            if d == c:
                return True
            elif d > c:
                b -= 1
            else:
                a += 1
        return False
