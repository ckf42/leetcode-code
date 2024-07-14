class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        timeCount = 0
        currTime = 0
        endTime = 0
        for t in timeSeries:
            timeCount += min(endTime, t) - currTime
            endTime = t + duration
            currTime = t
        return timeCount + duration
