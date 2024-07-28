class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(node, curr):
            if node is None:
                return False
            curr -= node.val
            if node.left is None and node.right is None:
                return curr == 0
            return dfs(node.left, curr) or dfs(node.right, curr)
        return dfs(root, targetSum)
