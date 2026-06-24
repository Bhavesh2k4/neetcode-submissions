class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]){//left sorted
                l=m+1;
            }else{
                r=m;
            }
        }
        //pivot index =l
        int pivot=l;
        if(target>=nums[l] && target <= nums[n-1]){
            l=pivot;
            r=n-1;
        }else{
            l=0;
            r=pivot-1;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
