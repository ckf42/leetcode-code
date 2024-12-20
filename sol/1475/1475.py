class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        res = [0] * n
        res[n - 1] = prices[n - 1]
        st = [prices[n - 1]]
        for i in range(n - 2, -1, -1):
            while len(st) != 0 and st[-1] > prices[i]:
                st.pop()
            res[i] = prices[i] - (0 if len(st) == 0 else st[-1])
            st.append(prices[i])
        return res

