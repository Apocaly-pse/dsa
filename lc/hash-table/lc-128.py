class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = list(set(nums))
        if (n := len(nums)) < 2:
            return n

        def find(i):
            if i == nums[i]:
                return i
            else:
                nums[i] = find(nums[i])
                return nums[i]

        def union(i, j):
            fa_i = find(i)
            fa_j = find(j)
            nums[fa_j] = fa_i
