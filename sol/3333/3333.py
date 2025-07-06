class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        n = len(word)
        m = 10 ** 9 + 7
        segLen = [1]
        allChoices = 1
        for i in range(1, n):
            if word[i] == word[i - 1]:
                segLen[-1] += 1
            elif segLen[-1] == 1:
                k -= 1
            else:
                allChoices = (allChoices * segLen[-1]) % m
                segLen.append(1)
        allChoices = (allChoices * segLen[-1]) % m
        if k <= len(segLen):
            return allChoices
        l = len(segLen)
        memo = [0] * k
        memo[0] = 1
        totalLen = 0
        for i, seg in enumerate(segLen):
            totalLen += seg
            newMemo = [0] * k
            for combLen in range(i + 1, min(k, seg + 1)):
                newMemo[combLen] = (newMemo[combLen - 1] + memo[combLen - 1]) % m
            for combLen in range(min(k, seg + 1), min(k, totalLen + 1)):
                newMemo[combLen] = (newMemo[combLen - 1] + memo[combLen - 1] - memo[combLen - seg - 1] + m) % m
            memo = newMemo
        return (allChoices - sum(memo) + m) % m
