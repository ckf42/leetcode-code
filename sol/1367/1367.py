class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def checker(node: Optional[TreeNode], ptr: Optional[ListNode]) -> bool:
            if ptr is None:
                return True
            if node is None or node.val != ptr.val:
                return False
            return checker(node.left, ptr.next) or checker(node.right, ptr.next)
        st = [root]
        while len(st) != 0:
            node = st.pop()
            if checker(node, head):
                return True
            if node.left is not None:
                st.append(node.left)
            if node.right is not None:
                st.append(node.right)
        return False
