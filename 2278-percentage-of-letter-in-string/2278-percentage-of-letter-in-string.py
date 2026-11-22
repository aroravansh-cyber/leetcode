class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        length=int(len(s))
        count=0
        for i in range(length):
            if s[i]==letter:
                count+=1
        return count*100//length