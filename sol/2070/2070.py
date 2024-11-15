class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        n = len(items)
        q = len(queries)
        items.sort(key=lambda x: x[0])
        itemIdx = 0
        qOrd = sorted(range(q), key=lambda i: queries[i])
        maxBeauty = 0
        res = [0] * q
        for qIdx in qOrd:
            while itemIdx < n and items[itemIdx][0] <= queries[qIdx]:
                maxBeauty = max(maxBeauty, items[itemIdx][1])
                itemIdx += 1
            res[qIdx] = maxBeauty
        return res
