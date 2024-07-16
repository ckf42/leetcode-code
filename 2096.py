class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def dfs(node, target, prefix):
            if node is None:
                return None
            if node.val == target:
                return prefix
            prefix.append('L')
            p = dfs(node.left, target, prefix)
            if p is not None:
                return p
            prefix[-1] = 'R'
            p = dfs(node.right, target, prefix)
            if p is not None:
                return p
            prefix.pop()
            return None
        p1 = dfs(root, startValue, [])
        p2 = dfs(root, destValue, [])
        l1 = len(p1)
        l2 = len(p2)
        i = 0
        while i < min(l1, l2) and p1[i] == p2[i]:
            i += 1
        return "U" * (l1 - i) + ''.join(p2[i:])
