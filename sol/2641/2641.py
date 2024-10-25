from collections import deque, defaultdict

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.val = 0
        lvl = deque()
        if root.left is not None:
            lvl.append((root.left, root))
        if root.right is not None:
            lvl.append((root.right, root))
        while (n := len(lvl)) != 0:
            d = defaultdict(int)
            st = []
            total = 0
            for _ in range(n):
                node, par = lvl.popleft()
                d[par] += node.val
                total += node.val
                st.append((node, par))
                if node.left is not None:
                    lvl.append((node.left, node))
                if node.right is not None:
                    lvl.append((node.right, node))
            for node, par in st:
                node.val = total - d[par]
        return root
