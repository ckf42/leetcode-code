class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        maxval = (r - l) * min(height[l], height[r])
        maxh = max(height)
        while l + 1 < r:
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
            maxval = max(maxval, (r - l) * min(height[l], height[r]))
            if maxval >= maxh * (r - l):
                break
        return maxval
