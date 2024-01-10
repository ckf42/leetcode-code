# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def leafSeq(node):
            if node is None:
                return
            if node.left is None and node.right is None:
                yield node.val
            else:
                yield from leafSeq(node.left)
                yield from leafSeq(node.right)

        return tuple(leafSeq(root1)) == tuple(leafSeq(root2))
