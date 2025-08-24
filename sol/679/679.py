from itertools import permutations
from fractions import Fraction

class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        knownFailComb = set()
        def bt(seq):
            nonlocal knownFailComb
            if seq in knownFailComb:
                return False
            l = len(seq)
            if l == 1:
                if seq[0] == 24:
                    return True
                knownFailComb.add(seq)
                return False
            for i in range(l - 1):
                a, b = seq[i], seq[i + 1]
                for c in (a + b, a - b, a * b) + (tuple() if b == 0 else (a / b,)):
                    if bt(seq[:i] + (c,) + seq[i + 2:]):
                        return True
            knownFailComb.add(seq)
            return False
        cards = tuple(Fraction(x) for x in cards)
        for perm in permutations(cards):
            if bt(perm):
                return True
        return False
