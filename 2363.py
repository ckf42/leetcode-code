from collections import defaultdict

class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        d = defaultdict(int)
        for item in items1 + items2:
            d[item[0]] += item[1]
        return sorted(d.items(), key=lambda x: x[0])
