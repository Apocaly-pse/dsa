from typing import List

class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        n=len(nums1)
        ans=0
        for i in range(n-1):
            if nums1[i]<nums1[i+1] and nums2[i]<nums2[i+1]:
                continue
            else: ans+=1 
        return ans



if __name__ == "__main__":
    s=Solution().minSwap
    print(s([1,2,3,9], [2,3,7,4]))
