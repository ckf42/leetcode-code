from collections import deque

class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = deque([root])
        while (s := len(q)) != 0:
            lvl = []
            for _ in range(s):
                node = q.popleft()
                lvl.append(node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            res.append(lvl.copy())
        return res[::-1]
