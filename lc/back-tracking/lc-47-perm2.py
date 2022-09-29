from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:

        n = len(nums)
        nums.sort()

        def backtrack(nums, used):
            if len(path) == n:
                ans.append(path[:])
                return
            for i in range(n):
                if used[i]:
                    continue
                if i and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                path.append(nums[i])
                backtrack(nums, used)
                path.pop()
                used[i] = False
        path, ans, used = [], [], [False] * n
        backtrack(nums, used)
        return ans


if __name__ == '__main__':
    s = Solution().permuteUnique
    print(s([1, 1, 2]))
    print(s([3, 3, 0, 3]))
    print(s([1, 2]))
    print(s([1]))
