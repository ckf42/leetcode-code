class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        n = len(s)
        prefixCount = [[0] * 5 for _ in range(n + 1)]  # [0, i)
        for i, c in enumerate(s):
            prefixCount[i + 1] = prefixCount[i].copy()
            prefixCount[i + 1][ord(c) - ord('0')] += 1
        res = -n
        for i in range(5):
            for j in range(i + 1, 5):
                minDiffIJ = [3 * n] * 4
                minDiffJI = [3 * n] * 4
                l = -1
                for e in range(k, n + 1):
                    fa = prefixCount[e][i]
                    fb = prefixCount[e][j]
                    while l < e - k \
                            and fa != (ffa := prefixCount[l + 1][i]) \
                            and fb != (ffb := prefixCount[l + 1][j]):
                        l += 1
                        state = ((ffa & 1) << 1) | (ffb & 1)
                        minDiffIJ[state] = min(minDiffIJ[state], ffa - ffb)
                        state = ((ffb & 1) << 1) | (ffa & 1)
                        minDiffJI[state] = min(minDiffJI[state], ffb - ffa)
                    if l == -1:
                        continue
                    # [l, e) has at least one char for both
                    res = max(
                        res,
                        fa - fb - minDiffIJ[((1 ^ (fa & 1)) << 1) | (fb & 1)],
                        fb - fa - minDiffJI[((1 ^ (fb & 1)) << 1) | (fa & 1)]
                    )
        return res
