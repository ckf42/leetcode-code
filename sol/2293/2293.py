class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        def alterMin(s, e):
            if s + 1 == e:
                return nums[s]
            else:
                return min(alterMin(s, (s + e) // 2), alterMax((s + e) // 2, e))
        
        def alterMax(s, e):
            if s + 1 == e:
                return nums[s]
            else:
                return max(alterMin(s, (s + e) // 2), alterMax((s + e) // 2, e))
        
        return alterMin(0, len(nums))
        
