class Solution:
    rec = [1]
    idx = [0, 0, 0]

    def nthUglyNumber(self, n: int) -> int:
        while n >= len(self.rec):
            l1 = self.rec[self.idx[0]] * 2
            l2 = self.rec[self.idx[1]] * 3
            l3 = self.rec[self.idx[2]] * 5
            x = min(l1, l2, l3)
            if x == l1:
                self.idx[0] += 1
            elif x == l2:
                self.idx[1] += 1
            else:
                self.idx[2] += 1
            if x != self.rec[-1]:
                self.rec.append(x)
        return self.rec[n - 1]
