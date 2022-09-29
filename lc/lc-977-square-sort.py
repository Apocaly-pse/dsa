from typing import List
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        a, b = 0, n - 1
        pos = n - 1
        ans = [0] * n
        def sq(x): return x * x
        if nums[a] <= 0 and nums[b] <= 0:
            while a <= b:
                if nums[a] < nums[b]:
                    ans[pos] = nums[a] * nums[a]
                    a += 1
                else:
                    ans[pos] = nums[b] * nums[b]
                    b -= 1
                pos -= 1
        elif nums[a] <= 0 and nums[b] >= 0:
            while a <= b:
                if -nums[a] > nums[b]:
                    ans[pos] = nums[a] * nums[a]
                    a += 1
                else:
                    ans[pos] = nums[b] * nums[b]
                    b -= 1
                pos -= 1
        else:
            while a <= b:
                if nums[a] > nums[b]:
                    ans[pos] = nums[a] * nums[a]
                    a += 1
                else:
                    ans[pos] = nums[b] * nums[b]
                    b -= 1
                pos -= 1

        return ans
