from collections import deque

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        item = []
        q = deque()
        for c in hand:
            if len(q) == 0:
                item = [1, c]
            elif q[-1][1] == c - 1:
                item = q.pop()
                item[0] += 1
                item[1] = c
            elif q[-1][1] == c:
                item = [1, c]
            else:
                return False
            if item[0] < groupSize:
                q.appendleft(item)
        return len(q) == 0
