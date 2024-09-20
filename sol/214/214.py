class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        srev = s[::-1]
        lps = [0] * n
        currLen = 0
        i = 1
        while i < n:
            if s[i] == s[currLen]:
                currLen += 1
                lps[i] = currLen
                i += 1
            elif currLen == 0:
                lps[i] = 0
                i += 1
            else:
                currLen = lps[currLen - 1]
        i = 0
        j = 0
        while i < n:
            if srev[i] == s[j]:
                i += 1
                j += 1
            elif j == 0:
                i += 1
            else:
                j = lps[j - 1]
        return srev + s[j:]
