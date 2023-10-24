# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res = list()

        def dfs(node, level):
            if node is None:
                return
            if level >= len(res):
                res.append(node.val)
            else:
                res[level] = max(res[level], node.val)
            if node.left is not None:
                dfs(node.left, level + 1)
            if node.right is not None:
                dfs(node.right, level + 1)

        dfs(root, 0)
        return res
