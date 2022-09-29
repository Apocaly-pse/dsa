from itertools import groupby


def method1(s='1', n=10):
    ans = []
    for _ in range(n):
        s = "".join([str(len(list(j))) + i for i, j in groupby(s)])
        print(s)
        ans.append(s)
    return ans


# print(method1(s='1', n=10))
'''
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211
11131221133112132113212221
[Finished in 54ms]
'''

import re


def lookandsay(limit, sequence=21):

    if limit > 1:

        return lookandsay(limit - 1, "".join([str(len(match.group())) + match.group()[0] for matchNum, match in enumerate(re.finditer(r"(\w)\1*", str(sequence)))]))

    else:

        return sequence


# for i in range(10):
#     print(lookandsay(i))
# exit()
def A005150(n):
    seq = [1] + [None] * (n - 1)  # allocate entire array space

    def say(s):
        acc = ''  # initialize accumulator
        while len(s) > 0:
            i = 0
            c = s[0]  # char of first run
            while (i < len(s) and s[i] == c):  # scan first digit run
                i += 1
            acc += str(i) + c  # append description of first run
            if i == len(s):
                break  # done
            else:
                s = s[i:]  # trim leading run of digits
        return acc

    for i in range(1, n):
        seq[i] = int(say(str(seq[i - 1])))
    return seq
print(A005150(10))

# def cmp(x, y):
#     if x == y:
#         return 0
#     else:
#         return -1 if x < y else 1


# def sign(n):
#     return cmp(n, 0)


# def say(a):
#     r = 0
#     p = 0
#     while a > 0:
#         c = 3 - sign((a % 100) % 11) - sign((a % 1000) % 111)
#         r += (10 * c + (a % 10)) * 10**(2 * p)
#         a /= 10**c
#         p += 1
#     return r


# a = 1

# for i in range(1, 20):
#     print(i, a)
#     a = say(a)
