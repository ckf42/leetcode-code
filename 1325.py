class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.left is not None:
            root.left = self.removeLeafNodes(root.left, target)
        if root.right is not None:
            root.right = self.removeLeafNodes(root.right, target)
        if root.val == target and root.left is None and root.right is None:
            return None
        else:
            return root
