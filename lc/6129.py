from typing import List


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        if nums.count(0) == 0:
            return 0
        ans = []
        n = len(nums)
        tmp = 0
        nums.append(1)
        for i in range(n+1):
            if nums[i] == 0:
                tmp += 1
            elif tmp!=0:
                ans.append(tmp)
                tmp = 0

        print(ans)
        res = len(ans) + sum(ans)
        for j in ans:
            for k in range(2, j):
                res += k
        return res-ans.count(1)


# nums = [1,3,0,0,2,0,0,4]
# nums = [0, 0, 0, 2, 0, 0]
nums=[0,1,0,0,1,0,0,0]
s = Solution()
aa = s.zeroFilledSubarray(nums)
print(aa)
