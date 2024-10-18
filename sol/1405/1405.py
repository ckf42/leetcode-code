import heapq as hq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        h = []
        for letter, count in zip('abc', (a, b, c)):
            if count != 0:
                h.append((-count, letter))
        hq.heapify(h)
        res = ''
        buff = None
        while len(h) != 0:
            count, letter = hq.heappop(h)
            if len(res) >= 2 and res[-2] == letter == res[-1]:
                buff = (count, letter)
                if len(h) != 0:
                    count, letter = hq.heappop(h)
            if buff is not None and buff[1] == letter:
                break
            res += letter
            if count != -1:
                hq.heappush(h, (count + 1, letter))
            if buff is not None:
                hq.heappush(h, buff)
                buff = None
        return res

