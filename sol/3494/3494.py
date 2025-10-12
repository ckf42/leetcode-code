class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n = len(skill)
        freeTime = [0] * n
        baseDelay = [0] * (n + 1)
        for i, sk in enumerate(skill):
            baseDelay[i + 1] = baseDelay[i] + sk
        for m in mana:
            minStart = max(0, max(a - m * b for a, b in zip(freeTime, baseDelay)))
            for i in range(n):
                freeTime[i] = minStart + m * baseDelay[i + 1]
        return freeTime[-1]

