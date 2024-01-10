# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root is None:
            return 0
        stack = [root]
        res = 0
        while len(stack) != 0:
            node = stack.pop()
            if low <= node.val <= high:
                res += node.val
            if node.left is not None and low < node.val:
                stack.append(node.left)
            if node.right is not None and node.val < high:
                stack.append(node.right)
        return res
