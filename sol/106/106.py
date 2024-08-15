class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        h = dict()
        for i, x in enumerate(inorder):
            h[x] = i
        n = len(inorder)
        def gen(ii, ij, pi, pj):
            if ii >= ij:
                return None
            val = postorder[pj - 1]
            l = h[val] - ii
            return TreeNode(
                    val,
                    gen(ii, ii + l, pi, pi + l),
                    gen(ii + l + 1, ij, pi + l, pj - 1)
            )
        return gen(0, n, 0, n)
