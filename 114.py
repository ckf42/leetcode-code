class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def flatter(node: TreeNode) -> tuple[TreeNode | None, TreeNode | None]:
            if node is None:
                return (None, None)
            lh, lt = flatter(node.left)
            rh, rt = flatter(node.right)
            node.left = None
            ptr = node
            if lh is not None:
                ptr.right = lh
                ptr = lt
            if rh is not None:
                ptr.right = rh
                ptr = rt
            return (node, ptr)
        flatter(root)
