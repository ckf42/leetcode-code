class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 is None or root2 is None:
            return root1 is None and root2 is None
        if root1.val != root2.val:
            return False
        l1, r1 = root1.left, root1.right
        if r1 is None or (l1 is not None and l1.val > r1.val):
            l1, r1 = r1, l1
        l2, r2 = root2.left, root2.right
        if r2 is None or (l2 is not None and l2.val > r2.val):
            l2, r2 = r2, l2
        return self.flipEquiv(l1, l2) and self.flipEquiv(r1, r2)

