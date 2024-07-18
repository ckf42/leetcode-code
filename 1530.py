from collections import defaultdict

class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        count = 0
        def dfs(node):
            d = defaultdict(int)
            if node is None:
                return d
            if node.left is None and node.right is None:
                d[0] = 1
                return d
            ld = dfs(node.left)
            rd = dfs(node.right)
            lk = sorted(ld.keys())
            rk = sorted(rd.keys())
            nonlocal count
            for a in lk:
                for b in rk:
                    if a + b + 2 > distance:
                        break
                    count += ld[a] * rd[b]
            for a in lk:
                if a + 2 >= distance:
                    break
                d[a + 1] += ld[a]
            for b in rk:
                if b + 2 >= distance:
                    break
                d[b + 1] += rd[b]
            return d
        dfs(root)
        return count
