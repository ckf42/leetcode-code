class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        if n < m * k:
            return -1
        l = min(bloomDay)
        r = max(bloomDay) + 1
        while l < r:
            p = (l + r) // 2
            bonquet = 0
            segCount = 0
            for x in bloomDay:
                if x <= p:
                    segCount += 1
                else:
                    bonquet += segCount // k
                    segCount = 0
                if bonquet >= m:
                    break
            bonquet += segCount // k
            if bonquet < m:
                l = p + 1
            else:
                r = p
        return l
