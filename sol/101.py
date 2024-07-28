class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        l, r = [root], [root]
        while len(l) != 0:
            x = l.pop()
            y = r.pop()
            c = (x is None) + (y is None)
            if c == 1:
                return False
            if c == 2:
                continue
            if x.val != y.val:
                return False
            l.append(x.left)
            l.append(x.right)
            r.append(y.right)
            r.append(y.left)
        return True
