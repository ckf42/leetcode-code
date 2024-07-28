# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def dfs(node, mask):
            if node is None:
                return 0
            mask ^= (1 << node.val)
            if node.left is None and node.right is None:
                return 1 if mask.bit_count() <= 1 else 0
            return dfs(node.left, mask) + dfs(node.right, mask)

        return dfs(root, 0)
