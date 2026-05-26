class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
        while(!q.empty()){
            pair<int,int> top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i].first;
                int dy=y+dir[i].second;
                if(dx>=0 && dx<n && dy>=0 && dy<m  && grid[dx][dy]==INT_MAX && vis[dx][dy]==false){
                    vis[dx][dy]=true;
                    q.push({dx,dy});
                    grid[dx][dy]=grid[x][y]+1;
                }
            }
        }
    }
};
