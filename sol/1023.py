class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        n = len(pattern)
        def match(q):
            j = 0
            for i, c in enumerate(q):
                if j < n and c == pattern[j]:
                    j += 1
                elif c.isupper():
                    return False
            return j == n
        return [match(q) for q in queries]
