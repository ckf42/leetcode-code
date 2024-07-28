class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        return frozenset((min(r) for r in matrix)).intersection((max(c) for c in zip(*matrix)))
