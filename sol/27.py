class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ptr = 0
        for n in nums:
            if n != val:
                nums[ptr] = n
                ptr += 1
        return ptr
        
