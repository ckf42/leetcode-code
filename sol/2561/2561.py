from collections import Counter

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        c = Counter(basket1 + basket2)
        c1 = Counter(basket1)
        val1 = []
        val2 = []
        counter = 0
        total = 0
        for k, freq in c.items():
            if freq & 1:
                return -1
            target = freq // 2
            diff = c1[k] - target
            counter += diff
            total += abs(diff)
            if diff > 0:
                val1.append([k, diff])
            elif diff < 0:
                val2.append([k, -diff])
        if counter != 0:
            return -1
        if len(val1) == 0:
            return 0
        minEle = min(min(basket1), min(basket2))
        val1.sort()
        val2.sort()
        if val2[0][0] == minEle:
            val1, val2 = val2, val1
        res = 0
        ptr1 = 0
        ptr2 = len(val2) - 1
        if val1[0][0] == minEle:
            while val1[0][1] != 0:
                elim = min(val1[0][1], val2[ptr2][1])
                total -= 2 * elim
                res += elim * minEle
                val1[0][1] -= elim
                val2[ptr2][1] -= elim
                if val2[ptr2][1] == 0:
                    ptr2 -= 1
            ptr1 = 1
        while ptr1 < len(val1):
            k, freq = val1[ptr1]
            while freq > 0:
                elim = min(freq, val2[ptr2][1])
                freq -= elim
                val2[ptr2][1] -= elim
                res += min(min(k, val2[ptr2][0]), minEle * 2) * elim
                if val2[ptr2][1] == 0:
                    ptr2 -= 1
            ptr1 += 1
        return res
        
