# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        maxDist = 0

        def getContri(node):
            nonlocal maxDist
            if node is None:
                return (-1, False)
            leftContri, targetIsInLeft = getContri(node.left)
            rightContri, targetIsInRight = getContri(node.right)
            if node.val == start:
                maxDist = max(maxDist, max(leftContri, rightContri) + 1)
                return (0, True)
            elif targetIsInLeft or targetIsInRight:
                maxDist = max(maxDist, leftContri + rightContri + 2)
                return ((leftContri if targetIsInLeft else rightContri) + 1, True)
            else:
                return (max(leftContri, rightContri) + 1, False)

        getContri(root)
        return maxDist
