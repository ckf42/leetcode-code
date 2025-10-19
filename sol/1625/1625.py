class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        stack = [tuple(map(int, s))]
        pushed = set(stack)
        while len(stack) != 0:
            state = stack.pop()
            sl = state[n - b:] + state[:n - b]
            if sl not in pushed:
                pushed.add(sl)
                stack.append(sl)
            sl = tuple(((x + a) % 10) if i & 1 else x for i, x in enumerate(state))
            if sl not in pushed:
                pushed.add(sl)
                stack.append(sl)
        return ''.join(str(x) for x in min(pushed))
