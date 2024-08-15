from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if root is None:
            return res
        q = deque([root])
        fromFront = True
        while (s := len(q)) != 0:
            lvl = []
            for _ in range(s):
                if fromFront:
                    node = q.popleft()
                    lvl.append(node.val)
                    if node.left is not None:
                        q.append(node.left)
                    if node.right is not None:
                        q.append(node.right)
                else:
                    node = q.pop()
                    lvl.append(node.val)
                    if node.right is not None:
                        q.appendleft(node.right)
                    if node.left is not None:
                        q.appendleft(node.left)
            fromFront = not fromFront
            res.append(lvl.copy())
        return res
