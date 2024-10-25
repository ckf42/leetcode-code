class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        res = []
        for p in folder:
            if len(res) == 0 or not p.startswith(res[-1] + '/'):
                res.append(p)
        return res
