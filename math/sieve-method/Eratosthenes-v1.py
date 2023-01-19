from time import time
# from numba import jit

n = int(1e6)


# @jit(nopython=True)
def Eratosthenes(n):
    p = 0  # count prime
    prime = []  # save prime
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            prime.append(i)
            p = p + 1
            # if i * i <= n:
            j = i * i
            while j <= n:
                is_prime[j] = False
                j = j + i
    print(prime, "\nthe number of prime is: ", p)


s = time()
Eratosthenes(n)
e = time()
print(f"Eratosthenes: time is {e-s}s")
'''the number of prime is:  78498
Eratosthenes: time is 0.23691391944885254s'''
