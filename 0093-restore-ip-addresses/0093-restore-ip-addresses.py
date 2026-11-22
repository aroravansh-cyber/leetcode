class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:
        res=[]
        def backtrack(i,path):
            if len(path)==4:
                if i==len(s):
                    res.append(".".join(path))
                return
            for j in range(i+1,min(i+4,len(s)+1)):
                seg=s[i:j]
                if int(seg)>255 or (len(seg)>1 and seg[0]=='0'):
                    continue
                backtrack(j,path+[seg])
        if 4<=len(s)<=12:
            backtrack(0,[])
        return res
