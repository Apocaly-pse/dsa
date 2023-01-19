from functools import reduce
from math import factorial


def factorial_v1(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


def factorial_v2(n):
    return reduce(lambda x, y: x * y, range(1, n + 1))


print(factorial(10))
print(factorial_v1(10))  # 3628800
print(factorial_v2(10))  # 3628800
