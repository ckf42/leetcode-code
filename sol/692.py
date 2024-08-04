import heapq as hq

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        h = dict()
        for w in words:
            h[w] = h.get(w, 0) + 1
        pq = [(-v, k) for k, v in h.items()]
        hq.heapify(pq)
        res = [""] * k
        for i in range(k):
            res[i] = hq.heappop(pq)[1]
        return res
