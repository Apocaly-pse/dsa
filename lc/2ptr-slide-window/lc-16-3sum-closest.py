from typing import List
from math import inf


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        if nums[0] == nums[-1]:
            return nums[0] * 3
        ans = 0
        minGap = gap = inf
        for i in range((n := len(nums)) - 2):
            if target >= 0 and nums[i] > target:
                break  # 剪枝
            # 对i从左向右去重
            if i and nums[i - 1] == nums[i]:
                continue
            L, R = i + 1, n - 1
            while L < R:
                tmp = nums[i] + nums[L] + nums[R]
                gap = abs(tmp - target)
                if tmp < target:
                    if gap < minGap:
                        ans = tmp
                        minGap = gap
                    L += 1
                elif tmp > target:
                    if gap < minGap:
                        ans = tmp
                        minGap = gap
                    R -= 1
                else:  # 找到准确答案
                    return target
        return ans


if __name__ == '__main__':
    s = Solution().threeSumClosest
    print(s([-1, 2, 1, -4], 1))  # 2
    print(s([0, 0, 0], 1))  # 0
