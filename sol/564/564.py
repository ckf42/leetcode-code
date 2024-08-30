
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        ni = int(n)
        if ni <= 10:
            return str(ni - 1)
        if ni == 11:
            return "9"
        l = len(n)
        front = int(n[:(l + 1) // 2])
        def genPal(half: str, excludeLast: bool) -> str:
            if excludeLast:
                return half + half[-2::-1]
            else:
                return half + half[::-1]
        candidates = (
            genPal(str(front), (l & 1) == 1),
            genPal(str(front - 1), (l & 1) == 1),
            genPal(str(front + 1), (l & 1) == 1),
            '9' * (l - 1),
            '1' + '0' * (l - 1) + '1'
        )
        opt = ""
        mindiff = -1
        for xs in candidates:
            if xs == n:
                continue
            x = int(xs)
            if mindiff == -1:
                opt = xs
                mindiff = abs(x - ni)
            if (thisdiff := abs(x - ni)) < mindiff or (thisdiff == mindiff and x < ni):
                opt = xs
                mindiff = thisdiff
        return opt
