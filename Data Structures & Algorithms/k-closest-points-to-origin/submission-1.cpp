class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxi;
        for(int i=0;i<points.size();i++){
            int dist=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxi.push({dist, {points[i][0], points[i][1]}});
            if(maxi.size()>k){
                maxi.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxi.empty()){
            pair<int,pair<int,int>> p=maxi.top();
            maxi.pop();
            ans.push_back({p.second.first, p.second.second});
        }
        return ans;
    }
};
