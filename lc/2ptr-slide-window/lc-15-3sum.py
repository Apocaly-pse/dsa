from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        if (n := len(nums)) < 3 or nums[0] > 0 or nums[-1] < 0:
            return []
        if nums[0] == nums[-1] == 0:
            return [[0, 0, 0]]
        ans = []
        for i in range(n - 2):
            if nums[i] > 0:  # 此时不会出现等于0的情况了
                break
            # 对i从左向右去重
            if i and nums[i - 1] == nums[i]:
                continue
            L, R = i + 1, n - 1
            while L < R:
                tmp = nums[i] + nums[L] + nums[R]
                if tmp < 0:  # L右移
                    L += 1
                elif tmp > 0:
                    R -= 1
                else:  # 找到答案
                    ans.append([nums[i], nums[L], nums[R]])
                    L += 1
                    R -= 1
                    while L < R and nums[L - 1] == nums[L]:
                        L += 1
                    while L < R and nums[R] == nums[R - 1]:
                        R += 1
        return ans


if __name__ == '__main__':
    s = Solution().threeSum
    print(s([1, 0, -1, 0, -2, 2]))
    print(s([2, -1, -1, 0, 1, -2, -1]))
    print(s([-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6]))
    '''
    [[-2, 0, 2], [-1, 0, 1]]
    [[-2, 0, 2], [-1, -1, 2], [-1, 0, 1]]
    [[-4, -2, 6], [-4, 0, 4], [-4, 1, 3], [-4, 2, 2], [-2, -2, 4], [-2, 0, 2]]
    '''
