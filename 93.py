class Solution:
    def spliter(self, s: str, partToSplit: int) -> Generator[str, None, None]:
        if len(s) == 0 or partToSplit < 0:
            return
        if partToSplit == 0:
            sInt = int(s)
            if s[0] == '0':
                if sInt == 0 and len(s) == 1:
                    yield s
            elif 0 < sInt <= 255:
                yield s
            return
        if s[0] == '0':
            for c in self.spliter(s[1:], partToSplit - 1):
                yield '0.' + c
        else:
            for i in range(1, len(s)):
                if int(s[:i]) <= 255:
                    for c in self.spliter(s[i:], partToSplit - 1):
                        yield s[:i] + '.' + c
                else:
                    break

    def restoreIpAddresses(self, s: str) -> List[str]:
        yield from self.spliter(s, 3)
