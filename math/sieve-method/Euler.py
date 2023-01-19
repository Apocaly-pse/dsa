from time import time
# from numba import jit


# @jit(nopython=True)
def euler():
    MAXN = int(1e6)
    pri = []
    vis = [True] * (MAXN + 1)
    cnt = 0
    for i in range(2, MAXN):
        if vis[i]:
            pri.append(i)
            cnt += 1
        for j in range(cnt):
            if i * pri[j] > MAXN:
                break
            vis[i * pri[j]] = False  # 标记为合数
            if i % pri[j] == 0:  # 防止重复标记
                break

    print(pri, "\nthe number of prime is: ", cnt)


s = time()
euler()
e = time()
print(f"euler: time is {e-s}s")
'''the number of prime is:  78498
euler: time is 0.5525140762329102s

with numba jit:

the number of prime is:  78498
euler: time is 0.40300703048706055s
'''
