class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(baskets)
        nodes = []
        def build(l, r, parIdx):
            nonlocal nodes
            if r == l + 1:
                nodes.append([l, r, baskets[l], -1, -1, parIdx])
                return len(nodes) - 1
            idx = len(nodes)
            nodes.append([])
            m = (l + r) // 2
            lidx = build(l, m, idx)
            ridx = build(m, r, idx)
            nodes[idx] = [l, r, max(nodes[lidx][2], nodes[ridx][2]), lidx, ridx]
            return idx
        build(0, n, -1)
        def find(val, idx):
            if idx == -1 or nodes[idx][2] < val:
                return -1
            if nodes[idx][1] == nodes[idx][0] + 1:
                return nodes[idx][0]
            lidx, ridx = nodes[idx][3], nodes[idx][4]
            if lidx != -1 and nodes[lidx][2] >= val:
                return find(val, lidx)
            else:
                return find(val, ridx)
        def remove(loc, idx):
            nonlocal nodes
            if idx == -1 or loc < nodes[idx][0] or loc >= nodes[idx][1]:
                return
            if nodes[idx][0] == loc and nodes[idx][1] == loc + 1:
                nodes[idx][2] = 0
                return
            lidx, ridx = nodes[idx][3], nodes[idx][4]
            newval = -1
            if lidx != -1:
                remove(loc, lidx)
                newval = max(newval, nodes[lidx][2])
            if ridx != -1:
                remove(loc, ridx)
                newval = max(newval, nodes[ridx][2])
            nodes[idx][2] = newval
        res = 0
        for f in fruits:
            loc = find(f, 0)
            if loc == -1:
                res += 1
            else:
                remove(loc, 0)
        return res
