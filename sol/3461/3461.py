class Solution:
    def hasSameDigits(self, s: str) -> bool:
        tpl = list(map(int, s))
        while len(tpl) != 2:
            tpl = [(a + b) % 10 for a, b in zip(tpl[:-1], tpl[1:])]
        return tpl[0] == tpl[1]
