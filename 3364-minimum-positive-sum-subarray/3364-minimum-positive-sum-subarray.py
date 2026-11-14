class Solution:
    def minimumSumSubarray(self, nums, l, r):
        n = len(nums)
        ans = float('inf')
        for length in range(l, r + 1):
            for i in range(n - length + 1):
                subarray = nums[i:i+length]
                s = sum(subarray)
                if s > 0:
                    ans = min(ans, s)
        return ans if ans != float('inf') else -1