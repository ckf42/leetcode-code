from collections import deque

class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        if root.val == x or root.val == y:
            return False
        q = deque([(root, None)])
        knownPar = None
        while (s := len(q)) != 0:
            for _ in range(s):
                node, par = q.popleft()
                if node.val == x or node.val == y:
                    if knownPar is None:
                        knownPar = par
                    else:
                        return par != knownPar
                if node.left is not None:
                    q.append((node.left, node))
                if node.right is not None:
                    q.append((node.right, node))
            if knownPar is not None:
                return False
        return False
