import heapq as hq

class Solution:
    def clearStars(self, s: str) -> str:
        n = len(s)
        indices = [list() for _ in range(26)]
        keep = [True] * n
        h = []
        for i, c in enumerate(s):
            if c == '*':
                keep[i] = False
                keep[indices[hq.heappop(h)].pop()] = False
            else:
                v = ord(c) - ord('a')
                hq.heappush(h, v)
                indices[v].append(i)
        return ''.join(a for a, b in zip(s, keep) if b)
