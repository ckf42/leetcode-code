class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        isbal = True
        def dfs(node):
            if node is None:
                return 0
            ld = dfs(node.left)
            rd = dfs(node.right)
            nonlocal isbal
            if not isbal:
                return 0
            if abs(ld - rd) > 1:
                isbal = False
                return 0
            return max(ld, rd) + 1
        dfs(root)
        return isbal
