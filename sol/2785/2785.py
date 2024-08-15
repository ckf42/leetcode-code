class Solution:
    def sortVowels(self, s: str) -> str:
        res = list(s)
        refStr = 'AEIOUaeiou'
        refSet = frozenset(refStr)
        vowelCount = [0] * 10
        vowelIndices = list()
        for i, c in enumerate(s):
            if c in refSet:
                vowelIndices.append(i)
                vowelCount[refStr.index(c)] += 1
        ptr = 0
        for idx in vowelIndices:
            while vowelCount[ptr] == 0:
                ptr += 1
            res[idx] = refStr[ptr]
            vowelCount[ptr] -= 1
        return ''.join(res)

