# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        res = 0

        def ancestorMinMax(node, ancestors):
            nonlocal res
            res = max(res, abs(node.val - ancestors[0]), abs(node.val - ancestors[1]))
            prev = ancestors.copy()
            ancestors[0] = min(ancestors[0], node.val)
            ancestors[1] = max(ancestors[1], node.val)
            if node.left is not None:
                ancestorMinMax(node.left, ancestors)
            if node.right is not None:
                ancestorMinMax(node.right, ancestors)
            ancestors[:] = prev[:]

        ancestorMinMax(root, [root.val, root.val])
        return res
