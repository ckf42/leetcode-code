class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        n = len(words)
        availability = [0] * 26
        for l in letters:
            availability[ord(l) - ord('a')] += 1
        meta = [[0, [0] * 26] for w in words]
        for i, w in enumerate(words):
            for c in w:
                idx = ord(c) - ord('a')
                meta[i][0] += score[idx]
                meta[i][1][idx] += 1
        suffix = [0] * n
        suffix[n - 1] = meta[n - 1][0]
        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] + meta[i][0]
        res = 0
        def backtrack(idx, currScore):
            if idx == n:
                nonlocal res
                res = max(res, currScore)
                return
            if currScore + suffix[idx] < res:
                return
            if all(availability[i] >= meta[idx][1][i] for i in range(26)):
                for i in range(26):
                    availability[i] -= meta[idx][1][i]
                backtrack(idx + 1, currScore + meta[idx][0])
                for i in range(26):
                    availability[i] += meta[idx][1][i]
            backtrack(idx + 1, currScore)
        backtrack(0, 0)
        return res
