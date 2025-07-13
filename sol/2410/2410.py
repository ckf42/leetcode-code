class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        n = len(trainers)
        ptr = 0
        res = 0
        for p in players:
            while ptr != n and trainers[ptr] < p:
                ptr += 1
            if ptr == n:
                break
            res += 1
            ptr += 1
        return res
