class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()
        get = mountain_arr.get
        s, e = 0, n - 1
        while s < e:
            m = (s + e) // 2
            if get(m) < get(m + 1):
                s = m + 1
            else:
                e = m
        peak = s
        s, e = 0, peak
        while s <= e:
            m = (s + e) // 2
            v = get(m)
            if v == target:
                return m
            if v < target:
                s = m + 1
            else:
                e = m - 1
        s, e = peak, n - 1
        while s <= e:
            m = (s + e) // 2
            v = get(m)
            if v == target:
                return m
            if v > target:
                s = m + 1
            else:
                e = m - 1
        return -1

