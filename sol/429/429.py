class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        res = []
        lvl = [root]
        while len(lvl) != 0:
            res.append([x.val for x in lvl])
            lvl = [y for x in lvl for y in x.children if y is not None]
        return res
