from utils import *


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if m == 1:
            return sum(grid[0])
        if n == 1:
            return sum(i[0] for i in grid)
        # 直接将grid用作dp数组
        dp = grid
        for i in range(1, n):
            dp[0][i] += dp[0][i - 1]
        for i in range(1, m):
            dp[i][0] += dp[i - 1][0]
        # print(dp)
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] += min(dp[i][j - 1], dp[i - 1][j])
        return dp[-1][-1]


if __name__ == '__main__':
    s = Solution().minPathSum
    ans = s([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
    print(ans)  # 7
    ans = s([[1, 2, 3], [4, 5, 6]])
    print(ans)  # 12
