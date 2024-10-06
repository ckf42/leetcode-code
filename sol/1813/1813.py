class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        w1 = sentence1.split(' ')
        w2 = sentence2.split(' ')
        n1 = len(w1)
        n2 = len(w2)
        if n1 == n2:
            return w1 == w2
        n = min(n1, n2)
        ptr1 = 0
        ptr2 = 0
        while ptr1 < n and w1[ptr1] == w2[ptr1]:
            ptr1 += 1
        while ptr2 < n - ptr1 and w1[n1 - 1 - ptr2] == w2[n2 - 1 - ptr2]:
            ptr2 += 1
        return ptr1 + ptr2 == n

