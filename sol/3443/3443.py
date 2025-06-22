class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        counts =  [0] * 4
        res = -1
        for c in s:
            match c:
                case 'N':
                    counts[0] += 1
                case 'S':
                    counts[1] += 1
                case 'E':
                    counts[2] += 1
                case 'W':
                    counts[3] += 1
            d = abs(counts[0] - counts[1]) + abs(counts[2] - counts[3])
            res = max(
                res,
                d + min(
                    k,
                    min(counts[0], counts[1]) + min(counts[2], counts[3])
                ) * 2
            )
        return res
