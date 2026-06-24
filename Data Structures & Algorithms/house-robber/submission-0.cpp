class Solution {
public:

    int solve(vector<int> &dp,int i,vector<int> &nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int include=nums[i]+solve(dp,i+2,nums);
        int exclude=solve(dp,i+1,nums);
        dp[i]=max(include,exclude);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(dp,0,nums);
    }
};
