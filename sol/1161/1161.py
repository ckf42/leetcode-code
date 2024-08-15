from collections import deque

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        optSum = root.val
        res = 1
        lvl = 2
        q = deque()
        if root.left is not None:
            q.append(root.left)
        if root.right is not None:
            q.append(root.right)
        while (s := len(q)) != 0:
            tot = 0
            for _ in range(s):
                node = q.popleft()
                tot += node.val
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            if tot > optSum:
                optSum = tot
                res = lvl
            lvl += 1
        return res
