class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        minStr = '{'
        stack = [(root, '')]
        while len(stack) != 0:
            node, suff = stack.pop()
            suff += chr(97 + node.val)
            if node.left is None and node.right is None:
                minStr = min(minStr, suff[::-1])
            else:
                if node.left is not None:
                    stack.append((node.left, suff))
                if node.right is not None:
                    stack.append((node.right, suff))
        return minStr

