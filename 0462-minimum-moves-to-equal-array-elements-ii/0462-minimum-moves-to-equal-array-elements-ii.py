class Solution:
    def minMoves2(self, array):
        array.sort()
        median = array[len(array) // 2]
        return sum(abs(x - median) for x in array)