# def twoSum(numbers, target: int):
#     n = len(numbers)

#     b = n - 1
#     flag = False
#     for i in range(n):
#         ans = [i + 1]
#         x = target - numbers[i]
#         a = i + 1
#         while a <= b:
#             mid = a + (b - a) // 2
#             if numbers[mid] > x:
#                 b = mid - 1
#             elif numbers[mid] < x:
#                 a = mid + 1
#             else:
#                 ans.append(mid + 1)
#                 flag = True
#                 break
#         if flag:
#             return ans
# def twoSum(numbers, target: int):
#     n = len(numbers)
#     a, b = 0, n - 1
#     while(a < b):
#         if numbers[a] + numbers[b] == target:
#             return [a + 1, b + 1]
#         elif numbers[a] + numbers[b] < target:
#             a += 1
#         else:
#             b -= 1


# print(twoSum([2, 7, 34, 344], 9))
# print(twoSum([2, 7, 34, 344], 41))

s='hello'
s=list(s)
n=len(s)
for i in range(n//2):
    s[i],s[n-1-i]=s[n-1-i], s[i]
s = "".join(s)
print(s)