# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        assert root is not None
        target = None
        parent = dict()
        stack = [(root, None)]
        while len(stack) != 0:
            node, p = stack.pop()
            if node.val == start:
                target = node
            parent[node] = p
            for n in (node.left, node.right):
                if n is not None:
                    stack.append((n, node))
        visited = set()
        stack = [(target, 0)]
        res = 0
        while len(stack) != 0:
            node, d = stack.pop()
            if node in visited:
                continue
            res = max(res, d)
            visited.add(node)
            for nei in (node.left, node.right, parent[node]):
                if nei is not None:
                    stack.append((nei, d + 1))
        return res
        
            
