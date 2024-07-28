class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        i, j = 0, n - 1
        while j >= i + 1 and s[i] == s[j]:
            c = s[i]
            while i <= j and s[i] == c:
                i += 1
            while i <= j and s[j] == c:
                j -= 1
        return j - i + 1
