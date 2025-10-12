import bisect

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        n = len(spells)
        m = len(potions)
        potions.sort()
        spellIdx = sorted(range(n), key=lambda idx: spells[idx], reverse=True)
        res = [0] * n
        lastIdx = 0
        for idx in spellIdx:
            lastIdx = bisect.bisect_left(potions, (success + spells[idx] - 1) // spells[idx], lo=lastIdx)
            res[idx] = m - lastIdx
        return res
