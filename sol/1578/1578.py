class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        totalTime = sum(neededTime)
        s, e = 0, 1
        while s < len(colors):
            e = s + 1
            while e < len(colors) and colors[e] == colors[s]:
                e += 1
            totalTime -= max(neededTime[s:e])
            s = e
        return totalTime

