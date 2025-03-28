class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        def checkItv(itvList):
            currItvTail = 0
            runCount = 0
            for itv in itvList:
                if currItvTail <= itv[0]:
                    runCount += 1
                currItvTail = max(currItvTail, itv[1])
            return runCount >= 3
        if checkItv(sorted([(a, b) for a, _, b, _ in rectangles], key=lambda itv: itv[0])):
            return True
        return checkItv(sorted([(a, b) for _, a, _, b in rectangles], key=lambda itv: itv[0]))

