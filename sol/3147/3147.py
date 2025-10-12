class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        maxval = max(energy[n - k:])
        for i in range(n - k - 1, -1, -1):
            energy[i] += energy[i + k]
            maxval = max(maxval, energy[i])
        return maxval
