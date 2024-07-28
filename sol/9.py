class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x == 0:
            return True
        if x < 0 or x % 10 == 0:
            return False
        xx, y = x, 0
        while xx > 0:
            xx, r = divmod(xx, 10)
            y = y * 10 + r
        return x == y
