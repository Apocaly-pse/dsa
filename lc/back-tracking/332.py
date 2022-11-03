from collections import defaultdict
from typing import List

# from sortedcontainers import SortedDict

from collections import defaultdict

# exit()


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets_dict = defaultdict(list)
        for item in tickets:
            tickets_dict[item[0]].append(item[1])
        """
         {'JFK': ['SFO', 'ATL'], 'SFO': ['ATL'], 'ATL': ['JFK', 'SFO']})
        """
        path = ["JFK"]

        def backtracking(start_point):
            if len(path) == len(tickets) + 1:
                return True
            tickets_dict[start_point].sort()
            for _ in tickets_dict[start_point]:
                end_point = tickets_dict[start_point].pop(0)
                path.append(end_point)
                if backtracking(end_point):
                    return True
                path.pop()
                tickets_dict[start_point].append(end_point)

        backtracking("JFK")
        return path


# class Solution:
#     def findItinerary(self, tickets: List[List[str]]) -> List[str]:
#         targets = defaultdict(list)
#         for fr, to in tickets:
#             targets[fr].append([to, ])
#         print(targets)
#
#         def bt(ticketNum, res):
#             if len(res) == ticketNum + 1:
#                 return True
#
#             print(targets[res[-1]])
#             for k, v in targets[res[-1]].items():
#                 print(k, v)
#                 if v != 0:  # not zero
#                     res.append(k)
#                     # print(targets[res[-1]])
#                     # print(targets[res[-1]][k])
#                     targets[res[-1]][k] -= 1
#                     if bt(ticketNum, res):
#                         return True
#                     res.pop()
#                     targets[res[-1]][k] += 1
#             return False
#
#         res = ["JFK"]
#         bt(len(tickets), res)
#         return res
#

if __name__ == "__main__":
    s = Solution().findItinerary
    print(s([["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]))
