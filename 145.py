class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root is None:
            return res
        nodeSt = [root]
        visitSt = [False]
        while len(nodeSt) != 0:
            node = nodeSt.pop()
            visited = visitSt.pop()
            if node is None:
                continue
            if visited:
                res.append(node.val)
            else:
                nodeSt.append(node)
                visitSt.append(True)
                nodeSt.append(node.right)
                visitSt.append(False)
                nodeSt.append(node.left)
                visitSt.append(False)
        return res
