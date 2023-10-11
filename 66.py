class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if all(x == 9 for x in digits):
            return [1] + [0] * len(digits)
        digits[-1] += 1
        for i in range(len(digits) - 1, 0, -1):
            if digits[i] == 10:
                digits[i] = 0
                digits[i - 1] += 1
            else:
                break
        return digits
