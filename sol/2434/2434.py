class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)
        smallestIdxFrom = [n - 1] * n
        for i in range(n - 2, -1, -1):
            smallestIdxFrom[i] = smallestIdxFrom[i + 1]
            if s[i] <= s[smallestIdxFrom[i]]:
                smallestIdxFrom[i] = i
        t = []
        res = ''
        ptr = 0
        while ptr < n:
            while smallestIdxFrom[ptr] != ptr:
                t.append(s[ptr])
                ptr += 1
            res += s[ptr]
            ptr += 1
            if ptr == n:
                break
            c = s[smallestIdxFrom[ptr]]
            while len(t) != 0 and t[-1] <= c:
                res += t.pop()
        res += ''.join(t[::-1])
        return res
