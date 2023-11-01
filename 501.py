# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.maxCount = 0
        self.count = 0
        self.lastVal = None
        self.res = list()

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            if node.val != self.lastVal:
                self.count = 1
                self.lastVal = node.val
            else:
                self.count += 1
            if self.count == self.maxCount:
                self.res.append(self.lastVal)
            elif self.count > self.maxCount:
                self.maxCount = self.count
                self.res[:] = [self.lastVal]
            inorder(node.right)

        inorder(root)
        return self.res
