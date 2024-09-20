class Solution:
    class Cmp(str):
        def __lt__(self, other):
            return self + other > other + self
    def largestNumber(self, nums: List[int]) -> str:
        strnum = [str(x) for x in nums]
        strnum.sort(key=self.Cmp)
        res = "".join(strnum)
        return "0" if res[0] == "0" else res
