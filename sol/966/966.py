class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        origWords = set(wordlist)
        capWords = dict()
        vowelWords = dict()
        for i, w in enumerate(wordlist):
            ww = w.lower()
            if ww not in capWords:
                capWords[ww] = w
            for c in 'aeiouAEIOU':
                ww = ww.replace(c, '.')
            if ww not in vowelWords:
                vowelWords[ww] = w
        def getRes(word):
            if word in origWords:
                return word
            ww = word.lower()
            if ww in capWords:
                return capWords[ww]
            for c in 'aeiouAEIOU':
                ww = ww.replace(c, '.')
            if ww in vowelWords:
                return vowelWords[ww]
            return ""
        return [getRes(q) for q in queries]


        
