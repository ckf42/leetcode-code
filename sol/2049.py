class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        left = [None] * n
        right = [None] * n
        for i in range(1, n):
            if left[parents[i]] is None:
                left[parents[i]] = i
            else:
                right[parents[i]] = i
        maxScore = 0
        count = 0
        subSize = [1] * n
        def dfs(x):
            nonlocal maxScore
            nonlocal count
            prod = 1
            if left[x] is not None:
                subSize[x] += dfs(left[x])
                prod *= subSize[left[x]]
            if right[x] is not None:
                subSize[x] += dfs(right[x])
                prod *= subSize[right[x]]
            if x != 0:
                prod *= n - subSize[x]
            if prod > maxScore:
                count = 1
                maxScore = prod
            elif prod == maxScore:
                count += 1
            return subSize[x]
        dfs(0)
        return count

