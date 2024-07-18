class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        st = [(root, -float('inf'), float('inf'))]
        while len(st) != 0:
            node, lb, ub = st.pop()
            if node is None:
                continue
            if not (lb < node.val < ub):
                return False
            st.append((node.left, lb, node.val))
            st.append((node.right, node.val, ub))
        return True
