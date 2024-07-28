class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        l, r = 0, len(tokens) - 1
        res = 0
        score = 0
        while l <= r:
            while l < len(tokens) and power >= tokens[l]:
                power -= tokens[l]
                score += 1
                l += 1
            res = max(score, res)
            if score == 0:
                break
            power += tokens[r]
            score -= 1
            r -= 1
        return res
