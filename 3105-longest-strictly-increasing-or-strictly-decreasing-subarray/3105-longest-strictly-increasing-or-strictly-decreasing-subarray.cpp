class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length=nums.size();
        int answer=0;
        for(int i=0; i<length; i++)
            {
                int increase=1;
                int increase2=i+1;
                while(increase2<length && nums[increase2]>nums[increase2-1])
                {
                    increase++;
                    increase2++;
                }
                increase2=i+1;
                int decrease=1;
                while(increase2<length && nums[increase2] < nums[increase2-1])
                {
                    decrease++;
                    increase2++;
                }
                answer=max({answer,increase,decrease});
            }
        return answer;
    }
};