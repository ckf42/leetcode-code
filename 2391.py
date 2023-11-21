class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        res = 0
        travelTime = 0
        lastTravelTimes = [0] * 3
        # keys = 'GMP'
        for i, house in enumerate(garbage):
            res += len(house)
            # for idx, sig in enumerate(keys):
            #     if sig in house:
            #         lastTravelTimes[idx] = travelTime
            if 'G' in house:
                lastTravelTimes[0] = travelTime
            if 'M' in house:
                lastTravelTimes[1] = travelTime
            if 'P' in house:
                lastTravelTimes[2] = travelTime
            travelTime += travel[i] if i < len(travel) else 0
        return res + sum(lastTravelTimes)
