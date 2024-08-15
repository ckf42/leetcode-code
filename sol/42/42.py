class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        maxHeightOnLeft, maxHeightOnRight = 0, 0
        res = 0
        while l < r:
            if height[l] < height[r]:
                res += max(0, maxHeightOnLeft - height[l])
                maxHeightOnLeft = max(maxHeightOnLeft, height[l])
                l += 1
            else:
                res += max(0, maxHeightOnRight - height[r])
                maxHeightOnRight = max(maxHeightOnRight, height[r])
                r -= 1
        return res
