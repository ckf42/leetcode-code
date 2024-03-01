# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        nodes = [root]
        remainder = 1
        while len(nodes) != 0:
            prevVal = None
            newNodes = []
            for node in nodes:
                if node.val & 1 != remainder:
                    return False
                if prevVal is not None and (prevVal >= node.val if remainder == 1 else prevVal <= node.val):
                    return False
                prevVal = node.val
                if node.left is not None:
                    newNodes.append(node.left)
                if node.right is not None:
                    newNodes.append(node.right)
            nodes = newNodes
            remainder = 1 - remainder
        return True
