class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ranks = sorted(range(len(score)), reverse=True, key=lambda i: score[i])
        for r, idx in enumerate(ranks):
            if r >= 3:
                score[idx] = str(r + 1)
            elif r == 2:
                score[idx] = "Bronze Medal"
            elif r == 1:
                score[idx] = "Silver Medal"
            else:
                score[idx] = "Gold Medal"
        return score
