import math
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans=0
        for i in range(len(nums)):
            for j in range(i,len(nums)):
                product=1
                gcd=0
                lcm=1
                for n in nums[i:j+1]:
                    product*=n
                    gcd=math.gcd(gcd,n)
                    lcm=math.lcm(lcm,n)
                if product==gcd*lcm:
                    ans=max(ans,j-i+1)
        return ans