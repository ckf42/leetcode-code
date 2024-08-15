class Solution:
    def getImportance(self, employees: List['Employee'], eid: int) -> int:
        h = dict()
        for i, e in enumerate(employees):
            h[e.id] = i
        def dfs(idx):
            return employees[idx].importance + sum(
                dfs(h[s])
                for s in employees[idx].subordinates)
        return dfs(h[eid])
