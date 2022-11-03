from collections import Counter


class Solution:
    def equalFrequency(self, word: str) -> bool:
        c = Counter(word)
        v = c.values()
        vc = Counter(v)
        mv = max(v)
        print(f"c:{c}, vc:{vc}, mv:{mv}")
        if len(vc) > 2:
            return False
        if len(vc) == 1:
            return vc[1] > 0 or list(vc.values())[0] == 1

        for k, v in vc.items():
            if k == mv and vc[k] == 1 and k - 1 in vc:
                return True
            if k == 1 and v == 1:
                return True
        return len(vc) == 1


if __name__ == '__main__':
    s = Solution().equalFrequency
    print(s("aabbcc"))
    print(s("aabcc"))
    # print(s("aabc"))
    # print(s("abcc"))
    # print(s("aaabc"))
    # print(s("aaac"))
    # print(s("aacc"))
    # print(s("aabcd"))
    # print(s("aabbc"))
    # print(s("aabccdd"))
