class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        arr = [0] * (n + 1)
        for i, v in enumerate(stations):
            arr[max(0, i - r)] += v
            arr[min(n, i + r + 1)] -= v
        s = min(stations)
        e = sum(stations) + k + 1
        while s < e:
            m = (s + e) // 2
            feasible = True
            val = 0
            remain = k
            diff = arr.copy()
            for i in range(n):
                val += diff[i]
                if val >= m:
                    continue
                x = m - val
                if x > remain:
                    feasible = False
                    break
                else:
                    val += x
                    remain -= x
                    diff[min(n, i + 2 * r + 1)] -= x
            if feasible:
                s = m + 1
            else:
                e = m
        return e - 1

