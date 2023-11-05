class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        base = minutesToTest // minutesToDie + 1
        # math.log(125, 4 + 1) == 3.0000000000000004
        mul = 1
        counter = 0
        while mul < buckets:
            mul *= base
            counter += 1
        return counter
