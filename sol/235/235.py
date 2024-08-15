class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ptr = root
        while ptr is not None:
            if ptr.val == p.val or ptr.val == q.val:
                return ptr
            if ptr.val > p.val and ptr.val > q.val:
                ptr = ptr.left
            elif ptr.val < p.val and ptr.val < q.val:
                ptr = ptr.right
            else:
                return ptr
        return None
