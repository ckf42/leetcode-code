class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(op[1] == '+' for op in operations) * 2 - len(operations)
