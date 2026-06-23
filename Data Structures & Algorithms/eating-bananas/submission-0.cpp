class Solution {
public:
    bool cansolve(int m,int h,vector<int> &piles){
        int temp=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%m==0){
                temp+=piles[i]/m;
            }else{
                temp+=(piles[i]/m + 1);
            }
            if(temp>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int l=1;
        int r=maxi;
        int ans=maxi;
        while(l<r){
            int m=l+(r-l)/2;
            if(cansolve(m,h,piles)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};
