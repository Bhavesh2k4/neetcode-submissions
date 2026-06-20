class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=0;
        int s=0;
        int maxi=0;
        while(s<prices.size()){
            int profit=prices[s]-prices[b];
            maxi=max(maxi,profit);
            if(prices[s]-prices[b]<0){
                b=s;
            }
            s++;
        }
        return maxi;
    }
};
