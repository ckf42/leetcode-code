class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # performance of collections.Counter does not seem good enough
        res = 0
        charCounter = dict()
        for c in chars:
            charCounter[c] = charCounter.get(c, 0) + 1
        for w in words:
            failed = False
            counter = charCounter.copy()
            for c in w:
                if counter.get(c, 0) > 0:
                    counter[c] -= 1
                else:
                    failed = True
                    break
            if not failed:
                res += len(w)
        return res
