class Solution:
    def minMoves(self, nums: list[int]) -> int:
        m = max(nums)
        return sum(m - x for x in nums)