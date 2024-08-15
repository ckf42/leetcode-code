class Solution:
    @staticmethod
    def isRot(s: str) -> bool:
        return all(c in '0125689' for c in s) and any(c in '2569' for c in s)

    val = {0: 0}

    def calc(self, n):
        if n not in self.val:
            self.calc(n - 1)
            self.val[n] = self.val[n - 1] + self.isRot(str(n))

    def rotatedDigits(self, n: int) -> int:
        self.calc(n)
        return self.val[n]
