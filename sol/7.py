class Solution:
    INT_MAX = 2147483647
    INT_MAX_MUL = 1000000000

    def reverse(self, x: int) -> int:
        if x < 0:
            if x <= -self.INT_MAX_MUL:
                # python3: (-3) % 10 == 7
                lastDigit = 10 - (x % 10)
                x = -((x + lastDigit) // 10)
                rev = self.reverse(x)
                if (self.INT_MAX - rev) // self.INT_MAX_MUL >= lastDigit:
                    return -self.INT_MAX_MUL * lastDigit - rev
                else:
                    return 0
            else:
                return -self.reverse(-x)
        lastDigit = x % 10
        x //= 10
        y = 0
        mul = 1
        while x != 0:
            y *= 10
            y += x % 10
            x //= 10
            mul *= 10
        if (self.INT_MAX - y) // mul >= lastDigit:
            return lastDigit * mul + y
        else:
            return 0
        

