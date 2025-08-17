class Solution:
    def maximum69Number (self, num: int) -> int:
        mask = 1
        update = 0
        while mask <= num:
            if (num // mask) % 10 == 6:
                update = mask * 3
            mask *= 10
        return num + update
