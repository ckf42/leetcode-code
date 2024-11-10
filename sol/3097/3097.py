class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 1
        n = len(nums)
        freq = [0] * 32
        val = 0
        res = n + 1
        e = -1
        for s in range(n):
            while e < n - 1 and val < k:
                e += 1
                x = nums[e]
                ptr = 0
                m = 1
                while x >= m:
                    if x & m:
                        if freq[ptr] == 0:
                            val |= m
                        freq[ptr] += 1
                    ptr += 1
                    m <<= 1
            if val >= k:
                res = min(res, e - s + 1)
            x = nums[s]
            ptr = 0
            m = 1
            while x >= m:
                if x & m:
                    freq[ptr] -= 1
                    if freq[ptr] == 0:
                        val ^= m
                ptr += 1
                m <<= 1
        return -1 if res > n else res
