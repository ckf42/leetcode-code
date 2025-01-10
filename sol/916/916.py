class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        total = dict()
        for w in words2:
            for c in frozenset(w):
                total[c] = max(total.get(c, 0), w.count(c))
        return [
                w
                for w in words1
                if all(w.count(c) >= freq for c, freq in total.items())
        ]
