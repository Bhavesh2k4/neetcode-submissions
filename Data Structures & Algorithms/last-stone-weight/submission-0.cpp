class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxi;
        for(int i=0;i<stones.size();i++){
            maxi.push(stones[i]);
        }
        while(maxi.size()>1){
            int first=maxi.top();
            maxi.pop();
            int second=maxi.top();
            maxi.pop();
            if(first-second!=0){
                maxi.push(first-second);
            }
        }
        if(maxi.size()==1){
            return maxi.top();
        }
        return 0;
    }
};
