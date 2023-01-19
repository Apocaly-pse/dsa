from time import time
from numpy import array, int64, bool8, append
from numba import jit
n = int(1e6)

prime = array([], dtype=int64)  # save prime


@jit(nopython=True)
def Eratosthenes(n, prime):
    p = 0  # count prime

    is_prime = array([True] * (n + 1), dtype=bool8)
    is_prime[0] = is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            prime = append(prime, i)
            p = p + 1
            # if i * i <= n:
            j = i * i
            while j <= n:
                is_prime[j] = False
                j = j + i
    # print(prime.tolist(), "\nthe number of prime is: ", p)


s = time()
Eratosthenes(n, prime)
e = time()
print(f"Eratosthenes: time is {e-s}s")
'''the number of prime is:  78498
Eratosthenes: time is 0.23691391944885254s'''
