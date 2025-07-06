class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.freq1 = dict()
        for x in nums1:
            self.freq1[x] = self.freq1.get(x, 0) + 1
        self.n2 = nums2
        self.freq2 = dict()
        for x in nums2:
            self.freq2[x] = self.freq2.get(x, 0) + 1

    def add(self, index: int, val: int) -> None:
        v = self.n2[index]
        self.n2[index] += val
        self.freq2[v] -= 1
        v += val
        self.freq2[v] = self.freq2.get(v, 0) + 1

    def count(self, tot: int) -> int:
        return sum(freq * self.freq2.get(tot - x, 0) for x, freq in self.freq1.items())


