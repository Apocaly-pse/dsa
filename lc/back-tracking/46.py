from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)

        def bt():
            if len(path) == n:
                ans.append(path[:])
                return
            for i in range(n):
                if used[i]:
                    continue
                path.append(nums[i])
                used[i] = 1
                bt()
                path.pop()
                used[i] = 0
        ans, path, used = [], [], [0] * n
        bt()
        return ans

    def permute1(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)

        def bt():
            if len(path) == n:
                ans.append(path[:])
                return
            for i in range(n):
                if not used[i]:
                    path.append(nums[i])
                    used[i] = 1
                    bt()
                    path.pop()
                    used[i] = 0
        ans, path, used = [], [], [0] * n
        bt()
        return ans


if __name__ == '__main__':
    s = Solution().permute
    print(s([1, 2, 3]))
    print(s([1, 2]))
    print(s([1]))
