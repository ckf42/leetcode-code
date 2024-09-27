class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = dict()
        for w in words:
            ptr = root
            for c in w:
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
                ptr['#'] = ptr.get('#', 0) + 1
        n = len(words)
        res = [0] * n
        for i in range(n):
            ptr = root
            for c in words[i]:
                ptr = ptr[c]
                res[i] += ptr.get('#', 0)
        return res
