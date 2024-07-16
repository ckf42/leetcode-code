class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root is None:
            return res
        st = [root]
        while len(st) != 0:
            node = st.pop()
            res.append(node.val)
            if node.right is not None:
                st.append(node.right)
            if node.left is not None:
                st.append(node.left)
        return res
