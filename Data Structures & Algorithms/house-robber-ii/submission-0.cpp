class Solution {
private:
    int f(int i,vector<int>& nums,vector<int>& dp,int first){
        if(i==first)return nums[first];
        if(i<first)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+f(i-2,nums,dp,first);
        int notPick=f(i-1,nums,dp,first);
        return dp[i]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp1(n,-1);vector<int> dp2(n,-1);
        int skipF=f(n-1,nums,dp1,1);
        int skipL=f(n-2,nums,dp2,0);
        return max(skipF,skipL);
    }
};