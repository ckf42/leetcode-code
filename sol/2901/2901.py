class Solution:
    @classmethod
    def matchingHammingDist(cls, s1, s2):
        if len(s1) != len(s2):
            return False
        hasDiff = False
        for a, b in zip(s1, s2):
            if a != b:
                if not hasDiff:
                    hasDiff = True
                else:
                    return False
        return hasDiff

    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        prevIdx = [-1] * n
        seqLen = [0] * (n + 1)
        maxLenIdx = n
        for i, c in enumerate(groups):
            targetIdx = -1
            for idx in range(i):
                if groups[idx] != c and seqLen[idx] > seqLen[targetIdx] and self.matchingHammingDist(words[idx], words[i]):
                    targetIdx = idx
            prevIdx[i] = targetIdx
            seqLen[i] = seqLen[targetIdx] + 1
            if seqLen[i] > seqLen[maxLenIdx]:
                maxLenIdx = i
        l = seqLen[maxLenIdx]
        res = [''] * l
        ptr = maxLenIdx
        for i in range(l - 1, -1, -1):
            res[i] = words[ptr]
            ptr = prevIdx[ptr]
        return res
