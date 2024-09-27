class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        root = dict()
        for x in arr1:
            ptr = root
            for c in str(x):
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
        res = 0
        for x in arr2:
            ptr = root
            dep = 0
            for c in str(x):
                if c not in ptr:
                    break
                ptr = ptr[c]
                dep += 1
            res = max(res, dep)
        return res
