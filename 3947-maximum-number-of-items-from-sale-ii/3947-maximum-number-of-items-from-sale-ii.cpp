class Solution{
public:
    int maximumSaleItems(vector<vector<int>>& items,int budget){
        int n=items.size();
        vector<int> cnt(n+1,0),freeCnt(n+1,0);
        long long mn=LLONG_MAX,ans=0;
        for(auto &x:items){
            cnt[x[0]]++;
            mn=min(mn,(long long)x[1]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                freeCnt[i]+=cnt[j];
            }
            freeCnt[i]--;
        }
        vector<pair<int,int>> deals;
        for(auto &x:items){
            int f=x[0],p=x[1];
            if(freeCnt[f]>0 && p<2*mn){
                deals.push_back({p,freeCnt[f]});
            }
        }
        sort(deals.begin(),deals.end());

        for(auto &d:deals){
            long long take=min((long long)d.second,(long long)budget/d.first);
            ans+=2*take;
            budget-=take*d.first;
        }
        ans+=budget/mn;
        return ans;
    }
};