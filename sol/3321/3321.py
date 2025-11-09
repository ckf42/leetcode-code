from sortedcontainers import SortedList

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        res = [0] * (n - k + 1)
        freq = dict()
        total = 0
        for z in nums[:k - 1]:
            freq[z] = freq.get(z, 0) + 1
        top = SortedList()
        rest = SortedList()
        for z, f in freq.items():
            top.add((-f, -z))
            total += f * z
        while len(top) > x:
            ff, zz = top.pop()
            rest.add((-ff, -zz))
            total -= ff * zz
        for i in range(n - k + 1):
            z = nums[i + k - 1]
            f = freq.get(z, 0)
            if f != 0:
                if (-f, -z) in top:
                    total -= f * z
                    top.remove((-f, -z))
                else:
                    rest.remove((f, z))
            f += 1
            freq[z] = f
            top.add((-f, -z))
            total += f * z
            if len(top) > x:
                ff, zz = top.pop()
                total -= ff * zz
                rest.add((-ff, -zz))
            res[i] = total
            z = nums[i]
            f = freq[z]
            freq[z] = f - 1
            if (f, z) in rest:
                rest.remove((f, z))
                rest.add((f - 1, z))
            else:
                top.remove((-f, -z))
                top.add((1 - f, -z))
                total -= z
                if len(rest) != 0:
                    ff, zz = rest.pop()
                    total += ff * zz
                    top.add((-ff, -zz))
                if len(top) > x:
                    ff, zz = top.pop()
                    total -= ff * zz
                    rest.add((-ff, -zz))
        return res
