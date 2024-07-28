class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        top = None
        vote = 0
        for n in nums:
            if top == n:
                vote += 1
            elif vote == 0:
                top = n
                vote = 1
            else:
                vote -= 1
        return top
