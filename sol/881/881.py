class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        res = 0
        i = 0
        j = len(people) - 1
        while i < j:
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
            res += 1
        if i == j:
            res += 1
        return res
