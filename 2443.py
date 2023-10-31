class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        for i in range(num // 2, num + 1):
            if i + int(str(i)[::-1]) == num:
                return True
        return False

# class Solution:
#     values = None
# 
#     def sumOfNumberAndReverse(self, num: int) -> bool:
#         if Solution.values is None:
#             Solution.values = frozenset((
#                 b
#                 for i in range(100000 // 2 + 1)
#                 if (b := i + int(str(i)[::-1])) <= 100000
#             ))
#         return num in Solution.values
