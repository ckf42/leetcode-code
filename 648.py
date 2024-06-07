class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = dict()
        for w in dictionary:
            ptr = trie
            for c in w:
                if c not in ptr:
                    ptr[c] = dict()
                ptr = ptr[c]
            ptr['='] = w
        def rep(w: str) -> str:
            ptr = trie
            for c in w:
                if c not in ptr:
                    return w
                ptr = ptr[c]
                if '=' in ptr:
                    return ptr['=']
            return w
        return " ".join(rep(w) for w in sentence.split())
