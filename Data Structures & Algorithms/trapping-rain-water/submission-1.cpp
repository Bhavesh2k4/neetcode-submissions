class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lmax=height[l];
        int rmax=height[r];
        int area=0;
        while(l<r){
            if(lmax<rmax){
                area+=lmax-height[l];
                l++;
                lmax=max(lmax,height[l]);
            }
            else{
                area+=rmax-height[r];
                r--;
                rmax=max(rmax,height[r]);
            }
        }
        return area;
    }
};
