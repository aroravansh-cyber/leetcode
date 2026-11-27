class Solution{
public:
    int maximumSaleItems(vector<vector<int>>&items,int budget){
        int n=items.size();
        vector<int>value(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&items[j][0]%items[i][0]==0){
                    value[i]++;
                }
            }
        }

        vector<vector<int>>groups(budget+1);

        for(int i=0;i<n;i++){
            if(items[i][1]<=budget){
                groups[items[i][1]].push_back(value[i]);
            }
        }

        const int NEG=-1000000000;
        vector<int>dp(budget+1,NEG);
        dp[0]=0;

        int ans=0;

        for(int p=budget;p>=1;p--){
            if(groups[p].empty())continue;

            vector<int>has(budget+1,NEG);

            for(int v:groups[p]){
                for(int b=budget;b>=p;b--){
                    has[b]=max(has[b],dp[b-p]+v);
                    dp[b]=max(dp[b],dp[b-p]+v);
                }
            }

            for(int b=0;b<=budget;b++){
                if(has[b]!=NEG){
                    ans=max(ans,has[b]+(budget-b)/p);
                }
            }
        }

        return ans;
    }
};