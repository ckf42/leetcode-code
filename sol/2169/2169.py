class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        count = 0
        if num1 < num2:
            num1, num2 = num2, num1
        while num2 != 0:
            q, num1 = divmod(num1, num2)
            count += q
            num1, num2 = num2, num1
        return count
