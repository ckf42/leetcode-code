class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        minEle, secMinEle = 101, 101
        for n in prices:
            if n < minEle:
                minEle, secMinEle = n, minEle
            elif n < secMinEle:
                secMinEle = n
        tot = minEle + secMinEle
        return money - tot if money >= tot else money

