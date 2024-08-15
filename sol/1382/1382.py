class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        arr = []
        def lot(node):
            if node.left is not None:
                lot(node.left)
            arr.append(node.val)
            if node.right is not None:
                lot(node.right)
        lot(root)
        def buildTree(s, e):
            if e - s < 1:
                return None
            p = (s + e) // 2
            return TreeNode(arr[p], buildTree(s, p), buildTree(p + 1, e))
        return buildTree(0, len(arr))
