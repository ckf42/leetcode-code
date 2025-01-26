from collections import defaultdict, deque

class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        edges = defaultdict(list)
        for i, x in enumerate(favorite):
            edges[x].append(i)
        res = 0
        visited = [False] * n
        loopLenTwo = []
        loopSeed = [-1] * n
        # loops with tails
        for seed in range(n):
            if len(edges[seed]) != 0:
                continue
            fast = seed
            slow = seed
            inNewLoop = False
            while True:
                if loopSeed[fast] != -1 and loopSeed[fast] != seed:
                    break
                loopSeed[fast] = seed
                visited[fast] = True
                fast = favorite[fast]
                if loopSeed[fast] != -1 and loopSeed[fast] != seed:
                    break
                loopSeed[fast] = seed
                visited[fast] = True
                fast = favorite[fast]
                slow = favorite[slow]
                if fast == slow:
                    inNewLoop = True
                    break
            if not inNewLoop:
                continue
            slow = seed
            while slow != fast:
                fast = favorite[fast]
                slow = favorite[slow]
            l = 0
            while True:
                slow = favorite[slow]
                l += 1
                if slow == fast:
                    break
            res = max(res, l)
            if l == 2:
                loopLenTwo.append(fast)
        # loops without tail
        total = 0
        for i in range(n):
            if visited[i]:
                continue
            j = i
            l = 0
            while not visited[j]:
                visited[j] = True
                j = favorite[j]
                l += 1
            if l == 2:
                total += 2
            res = max(res, l)
        # loops of len 2, with tails
        for i in loopLenTwo:
            j = favorite[i]
            buff = deque((x for x in edges[i] if x != j))
            l1 = 0
            while (s := len(buff)) != 0:
                for _ in range(s):
                    x = buff.popleft()
                    buff.extend(edges[x])
                l1 += 1
            l2 = 0
            buff = deque((x for x in edges[j] if x != i))
            while (s := len(buff)) != 0:
                for _ in range(s):
                    x = buff.popleft()
                    buff.extend(edges[x])
                l2 += 1
            total += l1 + l2 + 2
        return max(res, total)
