from collections import defaultdict

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        edges = defaultdict(list)
        totalDeg = defaultdict(int)
        for a, b in pairs:
            edges[b].append(a)
            totalDeg[a] -= 1
            totalDeg[b] += 1
        buff = []
        for node in totalDeg:
            if totalDeg[node] > 0:
                buff.append(node)
                break
        if len(buff) == 0:
            buff.append(pairs[0][0])
        prev = None
        res = []
        while len(buff) != 0:
            node = buff[-1]
            if len(edges[node]) == 0:
                if prev is not None:
                    res.append((prev, node))
                prev = node
                buff.pop()
            else:
                buff.append(edges[node].pop())
        return res
        
