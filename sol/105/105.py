class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        h = dict()
        for i, x in enumerate(inorder):
            h[x] = i
        n = len(preorder)
        def gen(pi, pj, ii, ij):
            if pi >= pj:
                return None
            val = preorder[pi]
            l = h[val] - ii
            return TreeNode(
                    val,
                    gen(pi + 1, pi + l + 1, ii, ii + l),
                    gen(pi + l + 1, pj, ii + l + 1, ij)
            )
        return gen(0, n, 0, n)
