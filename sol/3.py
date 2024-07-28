class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        count = dict()
        res = 1
        i = 0
        for j, c in enumerate(s):
            count[c] = count.get(c, 0) + 1
            while count[c] > 1:
                count[s[i]] -= 1
                i += 1
            res = max(res, j - i + 1)
        return res
