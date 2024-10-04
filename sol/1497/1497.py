class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        rem = [0] * k
        for x in arr:
            rem[x % k] += 1
        for x in range(k):
            if x == 0 or x * 2 == k:
                if rem[x] & 1:
                    return False
            elif rem[x] != rem[k - x]:
                return False
        return True
