def manacher(s):
    # 马拉车算法
    s = '#' + '#'.join(s) + '#'
    p = [0] * len(s)
    idx = 0
    mx = 0
    for i in range(len(s)):
        if mx > i:
            p[i] = min(p[2 * idx - i], mx - i)
        else:
            p[i] = 1
        while i - p[i] >= 0 and i + p[i] < len(s) and s[i - p[i]] == s[i + p[i]]:
            p[i] += 1
        if i + p[i] > mx:
            mx = i + p[i]
            idx = i
    return max(p) - 1

# 使用马拉车算法求解最长回文子串
s = 'babcbabcbaccba'
result = manacher(s)
print(result)  # 输出: 7
