class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head is None:
            return None
        ptr = head
        n = 0
        while ptr is not None:
            n += 1
            ptr = ptr.next
        def gen(c, node: ListNode) -> tuple[TreeNode, ListNode]:
            if node is None:
                return (None, None)
            if c == 0:
                return (None, node)
            if c == 1:
                return (TreeNode(node.val), node.next)
            ln, node = gen(c // 2, node)
            t = TreeNode(node.val, ln, None)
            node = node.next
            t.right, node = gen(c - c // 2 - 1, node)
            return t, node
        return gen(n, head)[0]
