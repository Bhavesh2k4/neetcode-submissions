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
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> nums1,nums2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                nums1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                nums2.push_back(nums[i]);
            }
        }
        vector<int> dp1(nums1.size()+1,-1);
        vector<int> dp2(nums2.size()+1,-1);
        return max(solve(dp1,0,nums1),solve(dp2,0,nums2));
    }
};
