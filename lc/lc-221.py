from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        if m == 0 or n == 0:
            return 0
        maxSide = 0
        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] == 1
                    else:
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1]
                                       [j], dp[i][j - 1]) + 1
                    maxSide = max(maxSide, dp[i][j])
        return maxSide * maxSide


if __name__ == '__main__':
    s = Solution().maximalSquare
    print(s([["1", "0", "1", "0", "0"],
             ["1", "0", "1", "1", "1"],
             ["1", "1", "1", "1", "1"],
             ["1", "0", "0", "1", "0"]]))
