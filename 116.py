class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None
        def make(node):
            if node.left is None:
                return
            node.left.next = node.right
            if node.next is not None:
                node.right.next = node.next.left
            make(node.left)
            make(node.right)
        make(root)
        return root
