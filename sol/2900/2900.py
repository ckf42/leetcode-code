class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        prevIdx = [-1] * n
        lastOccur = [-1, -1]
        seqLen = [1] * (n + 1)
        seqLen[-1] = 0
        for i, c in enumerate(groups):
            if lastOccur[1 - c] != -1:
                prevIdx[i] = lastOccur[1 - c]
                seqLen[i] = seqLen[lastOccur[1 - c]] + 1
            lastOccur[c] = i
        gp = 1 if seqLen[lastOccur[1]] >= seqLen[lastOccur[0]] else 0
        ptr = lastOccur[gp]
        buff = []
        while ptr != -1:
            buff.append(words[ptr])
            ptr = prevIdx[ptr]
        return buff[::-1]
