import bisect

class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        q = len(queries)
        res = [-1] * q
        qBuff = []
        for i in range(q):
            x, y = queries[i]
            if x > y:
                x, y = y, x
                queries[i] = queries[i][::-1]
            if x == y or heights[x] < heights[y]:
                print(f"res[{i}] = {y}")
                res[i] = y
            else:
                qBuff.append(i)
        qBuff.sort(key=lambda idx: queries[idx][1], reverse=True)
        st = []
        ptr = n - 1
        for idx in qBuff:
            x, y = queries[idx]
            while ptr != y:
                while len(st) != 0 and heights[ptr] >= heights[st[-1]]:
                    st.pop()
                st.append(ptr)
                ptr -= 1
            i = bisect.bisect(
                range(len(st) - 1, -1, -1),
                heights[x],
                key=lambda i: heights[st[i]]
            )
            if i < len(st):
                res[idx] = st[len(st) - 1 - i]
        return res
