class Solution {
public:
    int solve(vector<int> &dp,int i){
        if(i<=2){
            return i;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=solve(dp,i-1)+solve(dp,i-2);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};
