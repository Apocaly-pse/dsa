def aa(nums):
    if len(nums) == 1:
        return nums[0]
    l, r = 0, len(nums) - 1
    idx = len(nums) // 2
    while l < r:
        if nums[idx] == nums[idx - 1]:
            if (idx + 1) % 2 == 0:
                l = idx + 1
                # idx = l + (r - l) // 2
            else:
                r = idx - 2
            idx = l + (r - l) // 2
        elif nums[idx] == nums[idx + 1]:
            if idx % 2 == 0:
                l = idx + 2
                # idx = l + (r - l) // 2
            else:
                r = idx - 1
            idx = l + (r - l) // 2
        else:
            return nums[idx]
    return nums[l]


print(aa([0]))
print(aa([1, 1, 2, 2, 3]))
print(aa([0, 1, 1, 2, 2, 3, 3]))
print(aa([0, 0, 1, 1, 2, 3, 3]))
# exit()
print(aa([1, 1, 2, 3, 3, 4, 4, 8, 8]))
# exit()
print(aa([3, 3, 7, 7, 10, 11, 11]))


"""
思路: 二分法
先找中间元素, 如果两边有与中间元素相同的元素; 
不妨设为左边, 那么要寻找的元素一定出现在左边, 因为总数是奇数(2n+1),
"""
