def test(arr):
    i = 0
    n = len(arr)
    while i < len(arr) and len(arr) == n:
        if arr[i] == 0 and i != n - 1:
            arr[:] = arr[:i + 1] + [0] + arr[i + 1:n - 1]
            i += 2
        else:
            i += 1


if __name__ == '__main__':
    a = [1, 0, 2, 3, 0, 4, 5, 0]
    # a = [1, 2, 3, 0]
    test(a)
    print(a)
