from typing import List


class Solution:
    def maximumRobots(self, chargeTimes: List[int],
                      runningCosts: List[int], budget: int) -> int:
        if (n := len(chargeTimes)) == 1:
            return 1 if (cr := chargeTimes[0] + runningCosts[0]) \
                <= budget else 0
        dp = [0] * n
        dp[0] = 1 if cr <= budget else 0
        ma = chargeTimes[0]
        su = runningCosts[0]
        tmp=0
        for i in range(1, n):
            ma = max(ma, chargeTimes[i])
            su += runningCosts[i]
            tmp=ma + su * (i + 1)
            if tmp <= budget:
                dp[i] = dp[i - 1] + 1
            else:
                dp[i] = dp[i - 1]
