class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if denominator < 0:
            numerator = -numerator
            denominator = -denominator
        if numerator == 0:
            return "0"
        isNeg = numerator < 0
        if isNeg:
            numerator = -numerator
        iPart, r = divmod(numerator, denominator)
        prefix = ('-' if isNeg else '') + str(iPart)
        if r == 0:
            return prefix
        prefix += '.'
        buff = []
        seenRem = {r: 0}
        idx = 0
        while True:
            r *= 10
            q, r = divmod(r, denominator)
            buff.append(str(q))
            idx += 1
            if r == 0 or r in seenRem:
                break
            seenRem[r] = idx
        if r == 0:
            return prefix + ''.join(buff)
        return prefix + ''.join(buff[:seenRem[r]]) + '(' + ''.join(buff[seenRem[r]:]) + ')'

