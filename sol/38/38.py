class Solution:
    def countAndSay(self, n: int) -> str:
        buff = '1'
        newBuff = ''
        for _ in range(n - 1):
            newBuff = ''
            count = 1
            ele = buff[0]
            for x in buff[1:]:
                if x == ele:
                    count += 1
                else:
                    newBuff += f"{count}{ele}"
                    ele = x
                    count = 1
            newBuff += f"{count}{ele}"
            buff, newBuff = newBuff, buff
        return buff
