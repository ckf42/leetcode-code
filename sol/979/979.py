class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        totalMoves = 0
        def residual(node):
            if node is None:
                return 0
            lres = residual(node.left)
            rres = residual(node.right)
            nonlocal totalMoves
            totalMoves += abs(lres) + abs(rres)
            return lres + rres + node.val - 1
        residual(root)
        return totalMoves
