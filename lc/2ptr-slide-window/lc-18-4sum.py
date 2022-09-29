from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        if n < 4:
            return []
        ans = []
        for i in range(n - 3):
            if i and nums[i] == nums[i - 1]:
                continue  # 从左往右判重
            # 第一次剪枝
            if target >= 0 and nums[i] > target:
                break
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:  # 从左往右判重
                    continue
                # 第二次剪枝
                if target >= 0 and nums[i] + nums[j] > target:
                    break
                L = j + 1
                R = n - 1
                while L < R:
                    tmp = nums[i] + nums[j] + nums[L] + nums[R]
                    if tmp > target:
                        R -= 1
                    elif tmp < target:
                        L += 1
                    else:
                        ans.append([nums[i], nums[j], nums[L], nums[R]])
                        L += 1
                        R -= 1
                        while L < R and nums[L] == nums[L - 1]:
                            L += 1  # 从左往右判重
                        while L < R and nums[R] == nums[R + 1]:
                            R -= 1  # 从右往左判重
        return ans


if __name__ == '__main__':
    s = Solution().fourSum
    print(s([0] * 4, 0))  # [[0,0,0,0]]
    print(s([1, -2, -5, -4, -3, 3, 3, 5], -11))  # [[-5,-4,-3,1]]
    print(s([-2, -1, -1, 1, 1, 2, 2], 0))  # [[-2,-1,1,2],[-1,-1,1,1]]
    print(s([1, 0, -1, 0, -2, 2], 0))  # [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    print(s([2] * 4, 8))  # [[2,2,2,2]]
    print(s([2] * 5, 8))  # [[2,2,2,2]]
