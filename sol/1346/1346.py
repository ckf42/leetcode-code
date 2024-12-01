class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        h = set()
        for x in arr:
            if x * 2 in h or (((x ^ 1) & 1) and (x >> 1) in h):
                return True
            h.add(x)
        return False
