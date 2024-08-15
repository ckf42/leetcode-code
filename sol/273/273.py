class Solution:
    ones = ['One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten']
    tens = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
    teens = ['Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
    def basicPart(self, n: int) -> str:
        res = []
        if n >= 100:
            res.append(self.ones[n // 100 - 1])
            res.append("Hundred")
            n %= 100
        if n >= 20:
            res.append(self.tens[n // 10 - 2])
            n %= 10
        elif n >= 11:
            res.append(self.teens[n - 11])
            n = 0
        if n > 0:
            res.append(self.ones[n - 1])
        return " ".join(res)
    def numberToWords(self, n: int) -> str:
        if n == 0:
            return "Zero"
        res = []
        n, q = divmod(n, 1000)
        if q != 0:
            res.append(self.basicPart(q))
        if n > 0:
            n, q = divmod(n, 1000)
            if q != 0:
                res.append('Thousand')
                res.append(self.basicPart(q))
        if n > 0:
            n, q = divmod(n, 1000)
            if q != 0:
                res.append('Million')
                res.append(self.basicPart(q))
        if n > 0:
            n, q = divmod(n, 1000)
            if q != 0:
                res.append('Billion')
                res.append(self.basicPart(q))
        return " ".join(res[::-1])
