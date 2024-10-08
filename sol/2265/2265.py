# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        self.count = 0
        def sub(node):
            if node is None:
                return (0, 0)
            leftSum, leftCount = sub(node.left)
            rightSum, rightCount = sub(node.right)
            subSum = leftSum + rightSum + node.val
            subCount = leftCount + rightCount + 1
            if subSum // subCount == node.val:
                self.count += 1
            return (subSum, subCount)
        
        sub(root)
        return self.count
