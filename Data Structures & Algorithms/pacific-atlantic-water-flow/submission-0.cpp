class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> p(n,vector<bool> (m,false));
        vector<vector<bool>> a(n,vector<bool> (m,false));
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;
        for(int i=0;i<m;i++){
            p[0][i]=true;
            pq.push({0,i});
            a[n-1][i]=true;
            aq.push({n-1,i});
        }
        for(int i=0;i<n;i++){
            p[i][0]=true;
            pq.push({i,0});
            a[i][m-1]=true;
            aq.push({i,m-1});
        }
        bfs(heights,pq,p);
        bfs(heights,aq,a);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]==true && a[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>> q,vector<vector<bool>> &vis){
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int x=top.first;
            int y=top.second;
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy] && heights[dx][dy]>=heights[x][y]){
                    vis[dx][dy]=true;
                    q.push({dx,dy});
                }
            }
        }
    }
};