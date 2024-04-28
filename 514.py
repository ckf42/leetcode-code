
from collections import defaultdict

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        charIndices = defaultdict(list)
        for i, c in enumerate(ring):
            charIndices[c].append(i)
        l = len(ring)

        def dist(idx, targetIdx):
            v = abs(idx - targetIdx)
            return min(v, l - v)

        buffer = [
            [(dist(0, j) + 1, j) for j in charIndices[key[0]]],
            []
        ]
        ptr = 0
        for i in range(1, len(key)):
            buffer[1 - ptr] = [
                (min(v[0] + dist(v[1], j) for v in buffer[ptr]) + 1, j)
                for j in charIndices[key[i]]
            ]
            ptr = 1 - ptr
        return min(v[0] for v in buffer[ptr])

