from time import time
# from typing import List
# from numba import jit
# import taichi as ti
# ti.init()
n = int(1e6)

# @jit(nopython=True)

is_prime = [True] * (n + 1)
is_prime[0] = is_prime[1] = False


# @ti.func
def pre(n: int) -> None:

    for i in range(2, int(n**.5) + 1):
        if is_prime[i]:
            j = i * i
            while j <= n:
                is_prime[j] = False
                j += i


# @ti.kernel
def Eratosthenes(n: int) -> int:
    # ans = []
    cnt = 0
    pre(n)
    for j in range(n + 1):
        if is_prime[j]:
            # ans.append(j)
            cnt += 1
    return cnt


s = time()
print(Eratosthenes(n))
e = time()
print(f"Eratosthenes: time is {e-s}s")
'''the number of prime is:  78498
Eratosthenes: time is 0.23756694793701172s


with jit:

the number of prime is:  78498
Eratosthenes: time is 0.3765590190887451s
'''
