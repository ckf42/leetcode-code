class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        nextNum = 0
        res = list()
        for num in target:
            while True:
                nextNum += 1
                res.append("Push")
                if nextNum != num:
                    res.append("Pop")
                else:
                    break
        return res
