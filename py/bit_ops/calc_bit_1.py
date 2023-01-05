def calcbit1_v1(n):
    return bin(n).count("1")


def calcbit1_v2(n):
    ans = 0
    while n:
        tmp = n & 1
        ans += tmp
        n >>= 1
    return ans


def calcbit1_v3(n):
    diff = n
    while n:
        n >>= 1
        diff -= n
    return diff


def calcbit1_v4(n):
    total = 0
    tmp = n
    while tmp:
        tmp >>= 1
        total += tmp
    return n - total


if __name__ == "__main__":
    n = 123
    print(bin(n))
    print(calcbit1_v1(n))
    print(calcbit1_v2(n))
    print(calcbit1_v3(n))
    print(calcbit1_v4(n))
    # 0b1111011
    # 6
    # 6
    # 6
    # 6
