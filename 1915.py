class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        n = len(word)
        currMask = 0
        knownMaskCount = [0] * (1 << 10)
        knownMaskCount[0] = 1
        msk = {chr(ord('a') + i) : 1 << i for i in range(10)}
        for c in word:
            currMask ^= msk[c]
            knownMaskCount[currMask] += 1
        res = 0
        for m, c in enumerate(knownMaskCount):
            res += c * (c - 1)
            for i in range(10):
                res += c * knownMaskCount[m ^ (1 << i)]
        return res // 2
