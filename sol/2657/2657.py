class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        aSeen = [False] * (n + 1)
        bSeen = [False] * (n + 1)
        res = [0] * n
        count = 0
        for i in range(n):
            if A[i] == B[i]:
                count += 1
            else:
                count += aSeen[B[i]]
                count += bSeen[A[i]]
            aSeen[A[i]] = True
            bSeen[B[i]] = True
            res[i] = count
        return res
