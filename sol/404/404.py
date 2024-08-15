class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        res = 0
        st = [(root, False)]
        while len(st) != 0:
            node, isLeft = st.pop()
            if isLeft and node.left is None and node.right is None:
                res += node.val
            if node.left is not None:
                st.append((node.left, True))
            if node.right is not None:
                st.append((node.right, False))
        return res
