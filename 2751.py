class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        indices = sorted(range(n), key=lambda i: positions[i])
        res = []
        st = []
        for i in indices:
            if directions[i] == 'R':
                st.append([i, healths[i]])
            else:
                h = healths[i]
                while len(st) != 0:
                    if h <= st[-1][1]:
                        if h == st[-1][1]:
                            st.pop()
                        else:
                            st[-1][1] -= 1
                        h = -1
                        break
                    else:
                        st.pop()
                        h -= 1
                if h != -1:
                    res.append((i, h))
        res.extend(st)
        res.sort(key=lambda pr: pr[0])
        return (pr[1] for pr in res)
