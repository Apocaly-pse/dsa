from typing import List
# from math import factorial


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # return list(permutations(nums))
        n = len(nums)

        def backtrack(nums, used):
            if len(path) == n:
                ans.append(path[:])
                return
            for i in range(n):
                if used[i]:
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
    s = Solution().permute
    print(s([1, 2, 3]))
    print(s([1, 2]))
    print(s([1]))
