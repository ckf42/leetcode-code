class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        freq = [[0] * 26 for _ in range(26)]
        res = 0
        for w in words:
            freq[ord(w[0]) - ord('a')][ord(w[1]) - ord('a')] += 1
        hasSym = False
        for i in range(26):
            for j in range(i + 1, 26):
                res += min(freq[i][j], freq[j][i]) * 4
            res += (freq[i][i] // 2) * 4
            if freq[i][i] & 1:
                hasSym = True
        if hasSym:
            res += 2
        return res
