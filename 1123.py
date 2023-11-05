# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def postorder(node) -> tuple[Optional[TreeNode], int]:
            if node is None:
                return (None, -1)
            (leftRes, maxLeftDep) = postorder(node.left)
            (rightRes, maxRightDep) = postorder(node.right)
            if maxLeftDep == maxRightDep:
                return (node, maxLeftDep + 1)
            else:
                return (leftRes, maxLeftDep + 1) \
                    if maxLeftDep > maxRightDep \
                    else (rightRes, maxRightDep + 1)

        return postorder(root)[0]

