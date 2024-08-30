from math import gcd

class Solution:
    def fractionAddition(self, expression: str) -> str:
        num = 0
        den = 1
        n = len(expression)
        ptr = 0
        while ptr < n:
            if expression[ptr] == '+':
                ptr += 1
            offset = expression.find('/', ptr)
            if offset == -1:
                return ""
            thisNum = int(expression[ptr:offset])
            ptr = offset + 1
            offset = 0
            while ptr + offset < n and expression[ptr + offset].isdigit():
                offset += 1
            thisDen = int(expression[ptr:ptr + offset])
            num, den =  num * thisDen + thisNum * den, den * thisDen
            g = gcd(num, den)
            num //= g
            den //= g
            ptr += offset
        return f"{num}/{den}"
