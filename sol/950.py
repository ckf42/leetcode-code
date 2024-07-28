from collections import deque
from functools import cache

class Solution:
    @staticmethod
    @cache
    def _dd_(n):
        q = deque(range(n))
        st = []
        while len(q) != 0:
            st.append(q.popleft())
            q.rotate(-1)
        return tuple(st)

    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        res = [None] * len(deck)
        for i, x in enumerate(self._dd_(len(deck))):
            res[x] = deck[i]
        return res
