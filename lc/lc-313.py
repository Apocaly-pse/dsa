from typing import List


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        if n == 1:
            return 1
        dp = [0] * n
        dp[0] = 1
        dp[1]=primes[0]
        for i in range(2, n):
            if primes[i-2]*primes[i-2]<primes[i-1]:
                dp[i] = dp[i - 1]
        return dp


if __name__ == '__main__':
    s = Solution()
    for i in [(12, [2, 7, 13, 19]), (1, [2, 3, 5])]:
        ans = s.nthSuperUglyNumber(*i)
        print(ans)
