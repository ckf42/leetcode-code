class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda itv: itv[0])
        res = 0
        currDay = 1
        for s, e in meetings:
            if currDay < s:
                res += s - currDay
            currDay = max(currDay, e + 1)
        if currDay <= days:
            res += days - currDay + 1
        return res
