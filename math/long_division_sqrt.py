def find_nice(R, b=0):
    l, r = 0, 9
    while l <= r:
        mid = l + (r - l) // 2
        if (20 * b + mid) * mid > R:
            r = mid - 1
        else:
            l = mid + 1
    return l - 1


def mySqrt(n=0):
    dividend = quotient = reminder = 0
    # i = 0
    a = [0] * 100
    # while n:
    #     a[i] = n % 100
    #     n //= 100
    #     i += 1
    # quot = []
    i = 100
    a[i - 1] = 52
    a[i - 2] = 39
    for j in range(i - 1, -1, -1):
        dividend = reminder * 100 + a[j]
        tmp = find_nice(dividend, quotient)
        # quot.append(tmp)
        reminder = dividend - (20 * quotient + tmp) * tmp
        quotient = quotient * 10 + tmp
    # print(quot)
    return quotient


if __name__ == '__main__':
    n = 5239
    print('%100.100f' % n**.5)
    print(mySqrt(n))
