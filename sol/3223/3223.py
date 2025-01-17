class Solution:
    def minimumLength(self, s: str) -> int:
        return sum(
            2 >> (count & 1)
            for cidx in range(ord('a'), ord('z') + 1)
            if (count := s.count(chr(cidx))) != 0
        )
