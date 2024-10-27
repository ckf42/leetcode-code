class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        traversalOrder = []
        depths = dict()
        enterIdx = dict()
        exitIdx = dict()
        def dfs(node, dep):
            enterIdx[node.val] = len(traversalOrder)
            traversalOrder.append(node.val)
            depths[node.val] = dep
            if node.left is not None:
                dfs(node.left, dep + 1)
            if node.right is not None:
                dfs(node.right, dep + 1)
            exitIdx[node.val] = len(traversalOrder)
            traversalOrder.append(node.val)
        dfs(root, 0)
        nn = len(traversalOrder)
        maxDepFromLeft = [0] * nn
        maxDepFromRight = [0] * nn
        for i in range(1, nn):
            maxDepFromLeft[i] = max(maxDepFromLeft[i - 1], depths[traversalOrder[i]])
            maxDepFromRight[nn - 1 - i] = max(maxDepFromRight[nn - i], depths[traversalOrder[nn - 1 - i]])
        m = len(queries)
        res = [0] * m
        for i, q in enumerate(queries):
            res[i] = max(maxDepFromLeft[enterIdx[q] - 1], maxDepFromRight[exitIdx[q] + 1])
        return res

