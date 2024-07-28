class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k >= len(arr) - 1:
            return max(arr)
        elif k == 1:
            return max(arr[:2])
        headPtr = 0
        winCount = 0
        for i in range(1, len(arr)):
            if arr[headPtr] > arr[i]:
                winCount += 1
                if winCount == k:
                    return arr[headPtr]
            else:
                headPtr = i
                winCount = 1
        return arr[headPtr]
