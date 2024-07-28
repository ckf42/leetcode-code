class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        res = root.val
        def dfs(node):
            if node is None:
                return 0
            lf = dfs(node.left)
            rf = dfs(node.right)
            nonlocal res
            res = max(res, node.val + max(lf, 0) + max(rf, 0))
            return node.val + max(lf, rf, 0)
        dfs(root)
        return res
