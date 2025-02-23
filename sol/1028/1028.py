class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        seq = traversal.split('-')
        root = TreeNode(int(seq[0]))
        stack = [root]
        dep = 1
        for x in seq[1:]:
            if x == '':
                dep += 1
                continue
            val = int(x)
            while dep != len(stack):
                stack.pop()
            newNode = TreeNode(val)
            if stack[-1].left is None:
                stack[-1].left = newNode
            else:
                stack[-1].right = newNode
            stack.append(newNode)
            dep = 1
        return root
