class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int p1=nums[0];
        int p2=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=max(nums[i],max(nums[i]*p1,nums[i]*p2));
            p2=min(nums[i],min(nums[i]*p1,nums[i]*p2));
            p1=temp;
            ans=max(ans,p1);
        }
        return ans;
    }
};
