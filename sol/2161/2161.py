class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        smallBuff = []
        largeBuff = []
        count = 0
        for x in nums:
            if x == pivot:
                count += 1
            elif x < pivot:
                smallBuff.append(x)
            else:
                largeBuff.append(x)
        return smallBuff + [pivot] * count + largeBuff
