class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root is None:
            return []
        res = []
        def dfs(node, prefix):
            nonlocal res
            if node is None:
                return
            prefix.append(node.val)
            if node.left is None and node.right is None:
                res.append("->".join(str(x) for x in prefix))
            else:
                dfs(node.left, prefix)
                dfs(node.right, prefix)
            prefix.pop()
        dfs(root, [])
        return res
