class Solution:
    def __init__(self):
        self.subtreeSum = list()

    def calSubtreeSum(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0
        v = self.calSubtreeSum(node.left) + self.calSubtreeSum(node.right) + node.val
        self.subtreeSum.append(v)
        return v

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        totalSum = self.calSubtreeSum(root)
        halfSum = totalSum // 2
        closestVal = None
        closestDist = None
        for s in self.subtreeSum:
            if closestDist is None or abs(s - halfSum) < closestDist:
                closestDist = abs(s - halfSum)
                closestVal = s
                if closestVal == halfSum: # not sure if this really speeds up
                    break
        return (closestVal * (totalSum - closestVal)) % (int(1e9) + 7)
