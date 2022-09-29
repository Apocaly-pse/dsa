from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        L, R = 0, len(height) - 1
        ans = 0
        while L < R:
            if height[L] <= height[R]:
                ans = max(ans, height[L] * (R - L))
                L += 1

            else:
                ans = max(ans, height[R] * (R - L))
                R -= 1

        return ans


if __name__ == '__main__':
    s = Solution().maxArea
    print(s([1, 8, 6, 2, 5, 4, 8, 3, 7]))  # 49
    print(s([1, 1]))  # 1
