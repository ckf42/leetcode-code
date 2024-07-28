class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        oddCount = 0
        for x in arr:
            if x & 1:
                oddCount += 1
                if oddCount == 3:
                    return True
            else:
                oddCount = 0
        return False
