class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        vector<int> pre(nums.size());
        vector<int> suff(nums.size());
        pre[0]=1;
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        suff[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suff[i]=suff[i+1]*nums[i+1];
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int x=suff[i]*pre[i];
            res.push_back(x);
        }
        return res;

    }
};
