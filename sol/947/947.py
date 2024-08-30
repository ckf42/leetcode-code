from collections import defaultdict

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        rows = defaultdict(list)
        cols = defaultdict(list)
        for i, p in enumerate(stones):
            rows[p[0]].append(i)
            cols[p[1]].append(i)
        taken = [False] * n
        res = 0
        for i in range(n):
            if taken[i]:
                continue
            st = [i]
            gpSize = 0
            while len(st) != 0:
                idx = st.pop()
                if taken[idx]:
                    continue
                taken[idx] = True
                gpSize += 1
                for nb in rows[stones[idx][0]]:
                    if not taken[nb]:
                        st.append(nb)
                for nb in cols[stones[idx][1]]:
                    if not taken[nb]:
                        st.append(nb)
            res += gpSize - 1
        return res
