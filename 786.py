class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        nidx = 0
        didx = 1
        prelen = -1
        while prelen != k - 1:
            prelen = 0
            j = 1
            for i in range(n - 1):
                val = arr[i] * arr[didx]
                while j < n and val >= arr[j] * arr[nidx]:
                    j += 1
                prelen += n - j
            if prelen > k - 1:
                didx += 1
            elif prelen < k - 1:
                nidx += 1
        return [arr[nidx], arr[didx]]
