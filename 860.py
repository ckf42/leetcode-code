class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        billCount = [0, 0]
        for b in bills:
            if b == 5:
                billCount[0] += 1
            elif b == 10:
                if billCount[0] == 0:
                    return False
                else:
                    billCount[0] -= 1
                    billCount[1] += 1
            else:
                if billCount[1] >= 1 and billCount[0] >= 1:
                    billCount[0] -= 1
                    billCount[1] -= 1
                elif billCount[0] >= 3:
                    billCount[0] -= 3
                else:
                    return False
        return True

