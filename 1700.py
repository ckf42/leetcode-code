class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        takerCount = [0, sum(students)]
        takerCount[0] = len(students) - takerCount[1]
        ptr = 0
        while ptr < len(sandwiches):
            s = sandwiches[ptr]
            if takerCount[s] == 0:
                return sum(takerCount)
            else:
                takerCount[s] -= 1
                ptr += 1
        return 0
