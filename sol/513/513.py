# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.res = root.val
        self.height = 0

        def rln(node, height):
            if node is None:
                return
            if height >= self.height:
                self.res = node.val
                self.height = height
            rln(node.right, height + 1)
            rln(node.left, height + 1)

        rln(root, 0)
        return self.res
