class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        s = set(nums)
        news = set()
        for n in s:
            news.add(int(str(n)[::-1]))
        return len(s.union(news))

