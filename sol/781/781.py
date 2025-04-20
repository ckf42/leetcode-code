from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum(
            (q + i) // (i + 1) * (i + 1)
            for i, q in Counter(answers).items()
        )
