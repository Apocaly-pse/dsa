from typing import List


class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        tmp = set()
        ans = 0
        n = len(nums)
        nums.sort()
        for i in nums:
            isDiv = True
            for j in numsDivide:
                if j % i != 0 or i in tmp:
                    ans += 1
                    tmp.add(i)
                    isDiv = False
                    break
            if isDiv:
                break  # 找到了能整除的num

        return ans if ans < n else -1


print(Solution.minOperations(Solution, [4, 3, 6], [8, 2, 6, 10]))
