class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def mapper(x):
            if x < 10:
                return mapping[x]
            return mapper(x // 10) * 10 + mapping[x % 10]
        nums.sort(key=mapper)
        return nums
