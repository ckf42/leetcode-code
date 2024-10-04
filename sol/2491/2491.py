class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        if n == 2:
            return skill[0] * skill[1]
        m = n >> 1
        gpSum, r = divmod(sum(skill), m)
        if r != 0:
            return -1
        skill.sort()
        res = 0
        for i in range(m):
            if skill[i] + skill[n - 1 - i] != gpSum:
                return -1
            res += skill[i] * skill[n - 1 - i]
        return res
