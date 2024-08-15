class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if root is None:
            return root
        if depth == 1:
            newNode = TreeNode(val, root)
            return newNode
        stack = [(root, depth)]
        while len(stack) != 0:
            node, dep = stack.pop()
            if dep == 2:
                node.left, node.right = TreeNode(val, node.left), TreeNode(val, None, node.right)
            else:
                if node.left is not None:
                    stack.append((node.left, dep - 1))
                if node.right is not None:
                    stack.append((node.right, dep - 1))
        return root
