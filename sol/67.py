class Solution:
    def addBinary(self, a: str, b: str) -> str:
        na, nb = len(a), len(b)
        res = list()
        ptr = 0
        carry = False
        while ptr < na and ptr < nb:
            x = a[na - 1 - ptr] == "1"
            y = b[nb - 1 - ptr] == "1"
            res.append("1" if x ^ y ^ carry else "0")
            carry = (x and (y or carry)) or (y and carry)
            ptr += 1
        if ptr == nb:
            while ptr < na:
                x = a[na - 1 - ptr] == "1"
                res.append("1" if x ^ carry else "0")
                carry &= x
                ptr += 1
        else:
            while ptr < nb:
                x = b[nb - 1 - ptr] == "1"
                res.append("1" if x ^ carry else "0")
                carry &= x
                ptr += 1
        if carry:
            res.append("1")
        return "".join(res[::-1])

