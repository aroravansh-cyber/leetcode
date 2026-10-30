class Solution:
    def removeElement(self, nums, value):
        c = 0
        for i in range(len(nums)):
            if nums[i]!= value:
                nums[c] = nums[i]
                c=c+1
        return c