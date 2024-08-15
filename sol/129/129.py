class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def traversal(node, val):
            if node is None:
                return 0
            val = val * 10 + node.val
            if node.left is None and node.right is None:
                return val
            return traversal(node.left, val) + traversal(node.right, val)
        return traversal(root, 0)
