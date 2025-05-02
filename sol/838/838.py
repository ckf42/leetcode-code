class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        state = list(dominoes)
        fronts = [i for i in range(n) if dominoes[i] != '.']
        fallDir = [0] * n
        while len(fronts) != 0:
            proposedFall = []
            for x in fronts:
                d = 1 if state[x] == 'R' else -1
                nextToFall = x + d
                if nextToFall < 0 or nextToFall >= n or state[nextToFall] != '.':
                    continue
                fallDir[nextToFall] += d
                proposedFall.append(nextToFall)
            fronts.clear()
            for idx in proposedFall:
                if (v := fallDir[idx]) != 0:
                    state[idx] = 'R' if v == 1 else 'L'
                    fronts.append(idx)
                    fallDir[idx] = 0
        return ''.join(state)
