class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        cumsum = 0
        def rot(node: TreeNode) -> int:
            nonlocal cumsum
            if node.right is not None:
                rot(node.right)
            node.val += cumsum
            cumsum = node.val
            if node.left is not None:
                rot(node.left)
        rot(root)
        return root

