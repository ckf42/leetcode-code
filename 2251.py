import bisect

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        startTimes = sorted(f[0] for f in flowers)
        endTimes = sorted(f[1] for f in flowers)
        return tuple(
            bisect.bisect_right(startTimes, p) - bisect.bisect_left(endTimes, p)
            for p in people)
