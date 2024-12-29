from collections import deque

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        q = deque()
        if root is not None:
            q.append(root)
        while (n := len(q)) != 0:
            maxVal = q[0].val
            for _ in range(n):
                node = q.popleft()
                maxVal = max(maxVal, node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            res.append(maxVal)
        return res
