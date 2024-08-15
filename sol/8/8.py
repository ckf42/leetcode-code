class Solution:
    def myAtoi(self, s: str) -> int:
        gps = re.match(r'^ *([+-]?)(\d*)', s).groups()
        if len(gps[1]) == 0:
            return 0
        if gps[0] == '-':
            return -min(int(gps[1]), 2147483648)
        else:
            return min(int(gps[1]), 2147483647)
