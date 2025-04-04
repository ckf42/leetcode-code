class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def postorder(node) -> tuple[Optional[TreeNode], int]:
            if node is None:
                return (None, -1)
            (leftRes, maxLeftDep) = postorder(node.left)
            (rightRes, maxRightDep) = postorder(node.right)
            if maxLeftDep == maxRightDep:
                return (node, maxLeftDep + 1)
            elif maxLeftDep > maxRightDep:
                return (leftRes, maxLeftDep + 1)
            else:
                return (rightRes, maxRightDep + 1)
        return postorder(root)[0]

