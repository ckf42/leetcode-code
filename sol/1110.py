    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if root is None:
            return []
        if len(to_delete) == 0:
            return [root]
        to_delete = set(to_delete)
        foo = TreeNode(0, root)
        st = [(root, foo, False)]
        res = []
        while len(st) != 0:
            node, par, recorded = st.pop()
            if node is None:
                continue
            if node.val in to_delete:
                to_delete.remove(node.val)
                if par.left == node:
                    par.left = None
                else:
                    par.right = None
                st.append((node.left, node, False))
                st.append((node.right, node, False))
            else:
                if not recorded:
                    res.append(node)
                st.append((node.left, node, True))
                st.append((node.right, node, True))
        return res
