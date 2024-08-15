from collections import defaultdict

class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        bucket = defaultdict(list)
        for v, l in zip(values, labels):
            bucket[l].append(v)
        cont = []
        for b in bucket.values():
            b.sort(reverse=True)
            cont.extend(b[:min(len(b), useLimit)])
        cont.sort(reverse=True)
        return sum(cont[:min(len(cont), numWanted)])
