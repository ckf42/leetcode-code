class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(l, r, flip):
            if l is None:
                return
            if flip:
                l.val, r.val = r.val, l.val
            dfs(l.left, r.right, not flip)
            dfs(r.left, l.right, not flip)
        dfs(root.left, root.right, True)
        return root
