class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        lab = len(num1) + len(num2)
        mem = [0] * lab
        for i in range(len(num2) - 1, -1, -1):
            d = int(num2[i])
            for j in range(len(num1) - 1, -1, -1):
                mem[i + j + 1] += d * int(num1[j])
                q, mem[i + j + 1] = divmod(mem[i + j + 1], 10)
                mem[i + j] += q
        idx = 0
        while idx < lab and mem[idx] == 0:
            idx += 1
        return "".join(map(str, mem[idx:]))

