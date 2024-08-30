class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res = []
        def pot(node):
            if node is None:
                return
            for child in node.children:
                pot(child)
            nonlocal res
            res.append(node.val)
        pot(root)
        return res
