class Solution {
public:
    int solve(vector<int> &dp,int i,vector<int> &cost){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=cost[i]+min(solve(dp,i+1,cost),solve(dp,i+2,cost));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(dp,0,cost),solve(dp,1,cost));
    }
};
