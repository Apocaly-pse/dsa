def x2dec(x: str, k: int) -> int:
    """k-base number x to decimal system"""
    ans = 0
    for i in range(n := len(x)):
        ans += int(x[n - 1 - i]) * k**i
    return ans


def dec2x(x: int, k: int) -> str:
    """decimal number x to k-base system number"""
    ans = ''
    while x:
        x, r = divmod(x, k)
        ans = str(r) + ans
    return ans


if __name__ == '__main__':
    print(x2dec('12112', 3))
    print(dec2x(149, 3))
