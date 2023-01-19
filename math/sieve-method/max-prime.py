def isprime(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    i = 2
    while i * i <= n:
        if is_prime[i]:
            j = i * i
            while j <= n:
                is_prime[j] = False
                j += i
        i += 1
    for j in range(n, 0, -1):
        if is_prime[j]:
            return j


def main():
    n = eval(input())
    for _ in range(n):
        print(isprime(eval(input())))


if __name__ == "__main__":
    main()
