from time import time, sleep
from typing import List
from string import ascii_lowercase as abc
from random import randint, seed


# 错了, bs***sb被计算为2了
def NEXT1(s: str) -> List[int]:
    ans = [0]
    for i in range(1, len(s)):
        tmp = 0
        L, R = 0, i  # 用双指针进行计算
        while L < R:  # 还有优化空间
            if s[L] == s[R]:
                tmp += 1
            else:
                break
            L += 1
            R -= 1
        ans.append(tmp)
    return ans


def NEXT2(s: str) -> List[int]:
    ans = [0] * len(s)
    j = 0
    for i in range(1, len(s)):
        while j > 0 and s[i] != s[j]:
            j = ans[j - 1]
        if s[i] == s[j]:
            j += 1
        ans[i] = j
    return ans


def KMP(s1, s2):
    nxt = NEXT2(s2)
    ns1 = len(s1)
    j = 0
    for i in range(0, ns1):
        # 遇到不匹配的情况,j回退
        while j and s1[i] != s2[j]:
            j = nxt[j - 1]
        if s1[i] == s2[j]:
            j += 1
        if j == len(nxt):  # 匹配到模式串结尾
            return i - j + 1
    return -1  # 没找到


def test():
    seed(10)
    tests1 = ''.join(abc[randint(0, 25)] for _ in range(50))

    def testNext(str1, func):
        print(str1)
        s = time()
        ans = func(str1)
        e = time()
        print(f'{func}, total use: {e-s}s')
        return ans
    ans1 = testNext(tests1, NEXT2)
    sleep(1)
    ans2 = testNext(tests1, NEXT1)
    print(ans1)
    print(ans2)
    print(ans1 == ans2)
    '''
    <function NEXT2 at 0x1012f1b80>, total use: 1.2592999935150146s
    <function NEXT1 at 0x1012d5820>, total use: 1.4883067607879639s
    '''


if __name__ == '__main__':
    # test()
    s1 = "aabaabaaf"
    s2 = "aabaaf"
    nxt = NEXT2(s2)
    print(nxt)  # [0, 1, 0, 1, 2, 0]
    idx = KMP(s1, s2)
    print(idx)  # 3
