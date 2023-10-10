class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        scores = [0] * len(edges)
        for i, e in enumerate(edges):
            scores[e] += i
        idx = 0
        for i in range(1, len(edges)):
            if scores[i] > scores[idx]:
                idx = i
        return idx
