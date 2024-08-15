class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        created = dict()
        parent = dict()
        rootval = -1
        for p, c, l in descriptions:
            parent[c] = p
            if p not in created:
                created[p] = TreeNode(p)
            if c not in created:
                created[c] = TreeNode(c)
            rootval = p
            if l:
                created[p].left = created[c]
            else:
                created[p].right = created[c]
        while rootval in parent:
            rootval = parent[rootval]
        return created[rootval]lass Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        created = dict()
        isChild = set()
        for p, c, l in descriptions:
            isChild.add(c)
            if p not in created:
                created[p] = TreeNode(p)
            if c not in created:
                created[c] = TreeNode(c)
            if l:
                created[p].left = created[c]
            else:
                created[p].right = created[c]
        return created[next(k for k in created if k not in isChild)]
