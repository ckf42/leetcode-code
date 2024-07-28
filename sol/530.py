# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAdj(self, root: Optional[TreeNode]):
        assert root is not None
        minVal = root.val
        maxVal = root.val
        diff = 100001
        if root.left is not None:
            subTuple = self.getAdj(root.left)
            minVal = subTuple[0]
            diff = min(diff, root.val - subTuple[1], subTuple[2])
        if root.right is not None:
            subTuple = self.getAdj(root.right)
            maxVal = subTuple[1]
            diff = min(diff, subTuple[0] - root.val, subTuple[2])
        return (minVal, maxVal, diff)


    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        return self.getAdj(root)[2]
