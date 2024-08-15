class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root is None:
            return []
        res = []
        rec = []
        def dfs(node, curr):
            curr -= node.val
            rec.append(node.val)
            if node.left is None and node.right is None and curr == 0:
                res.append(rec[:])
            if node.left is not None:
                dfs(node.left, curr)
            if node.right is not None:
                dfs(node.right, curr)
            rec.pop()
        dfs(root, targetSum)
        return res
