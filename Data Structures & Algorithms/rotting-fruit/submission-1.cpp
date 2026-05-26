class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if (fresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        vector<pair<int,int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
        int time=-1;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                pair<int,int> top=q.front();
                int x=top.first;
                int y=top.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int dx=x+dir[i].first;
                    int dy=y+dir[i].second;
                    if( dx>=0 && dx<n && dy>=0 && dy<m  && grid[dx][dy]==1){
                        grid[dx][dy]=2;
                        q.push({dx,dy});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh==0){
            return time;
        }
        return -1;
    }
};
