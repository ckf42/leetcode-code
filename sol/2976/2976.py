class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        discont = int(1e9)
        dist = [[discont for __ in range(26)] for _ in range(26)]
        for i in range(26):
            dist[i][i] = 0
        for u, v, w in zip(original, changed, cost):
            uu = ord(u) - ord('a')
            vv = ord(v) - ord('a')
            dist[uu][vv] = min(dist[uu][vv], w)
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        res = 0
        for a, b in zip(source, target):
            aa = ord(a) - ord('a')
            bb = ord(b) - ord('a')
            if dist[aa][bb] == discont:
                return -1
            res += dist[aa][bb]
        return res
