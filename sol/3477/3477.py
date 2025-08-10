class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        unplaced = 0
        for f in fruits:
            for i, cap in enumerate(baskets):
                if cap >= f:
                    baskets.pop(i)
                    break
            else:
                unplaced += 1
        return unplaced
