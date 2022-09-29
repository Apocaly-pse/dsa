def construct2DArray(original, m: int, n: int):
    if len(original) != m * n:
        return []
    ans = [[]] * m
    for i in range(m):
        ans[i].append(original[(i * n) : (i * n + n)])
    return ans


print(construct2DArray([1, 2, 3, 4], 2, 2))
