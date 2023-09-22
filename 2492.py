from collections import defaultdict

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        edgeDict = defaultdict(list)
        for eidx, edge in enumerate(roads):
            edgeDict[edge[0]].append((edge[1], eidx))
            edgeDict[edge[1]].append((edge[0], eidx))
        visitedEdge = [False] * len(roads)
        visitedNode = [False] * n
        st = [1]
        while len(st) != 0:
            pt = st.pop()
            if visitedNode[pt - 1]:
                continue
            visitedNode[pt - 1] = True
            for nb, eidx in edgeDict[pt]:
                if not visitedEdge[eidx]:
                    visitedEdge[eidx] = True
                    st.append(nb)
        return min(roads[idx][2] for idx in range(len(roads)) if visitedEdge[idx])
