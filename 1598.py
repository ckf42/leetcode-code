class Solution:
    def minOperations(self, logs: List[str]) -> int:
        dep = 0
        for step in logs:
            match step:
                case '../':
                    dep = max(0, dep - 1)
                case './':
                    pass
                case _:
                    dep += 1
        return dep
