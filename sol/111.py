from collections import deque

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        dep = 1
        q = deque([root])
        while (s := len(q)) != 0:
            for _ in range(s):
                node = q.popleft()
                if node.left is None and node.right is None:
                    return dep
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            dep += 1
        return 0
