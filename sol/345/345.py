class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        idx = []
        for i, c in enumerate(s):
            if c in 'aeiouAEIOU':
                idx.append(i)
        n = len(idx)
        for i in range(n // 2):
            s[idx[i]], s[idx[n - 1 - i]] = s[idx[n - 1 - i]], s[idx[i]]
        return ''.join(s)
