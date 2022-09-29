from utils import *


class Solution:
    def smallestTrimmedNumbers(self,
                               nums: List[str],
                               queries: List[List[int]]) -> List[int]:
        n = len(nums)
        m = len(queries)
        ans = []
        for j in range(m):
            tmp = [[int(nums[i][-queries[j][-1]:]), i] for i in range(n)]
            tmp.sort()
            # print(tmp)
            ans.append(tmp[queries[j][0] - 1][-1])
        return ans


s = Solution()
print(s.smallestTrimmedNumbers(["24", "37", "96", "04"], [[2, 1], [2, 2]]))
