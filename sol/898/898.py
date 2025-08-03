class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        seen = set()
        buff = set()
        for x in arr:
            buff = {x | y for y in buff}
            buff.add(x)
            seen.update(buff)
        return len(seen)
