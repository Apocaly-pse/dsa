s = '12345'
ans = 0
for c in s:
    ans = int(c) + ans * 10
print(ans, type(ans))
# 12345 <class 'int'>

s = '12345'
ans = 0
for i in range(n := len(s)):
    ans += int(s[n - 1 - i]) * 10**i
print(ans, type(ans))
# 12345 <class 'int'>
