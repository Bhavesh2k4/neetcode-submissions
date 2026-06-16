class Solution {
public:
    string rotate(string s, int i, int dir) {
        // dir = +1 (up), -1 (down)
        int digit = s[i] - '0';
        digit = (digit + dir + 10) % 10;
        s[i] = digit + '0';
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool> vis;
        for(int i=0;i<deadends.size();i++){
            vis[deadends[i]]=true;
        }
        if(vis.find("0000")!=vis.end()){
            return -1;
        }
        queue<pair<string,int>> q;
        q.push({"0000",0});
        vis["0000"]=true;
        while(!q.empty()){
            pair<string,int> top=q.front();
            string pattern=top.first;
            int step=top.second;
            q.pop();
            if(pattern==target){
                return step;
            }
            for(int i=0;i<4;i++){
                string up=rotate(pattern,i,1);
                string down=rotate(pattern,i,-1);
                if(vis.find(up)==vis.end()){
                    q.push({up,step+1});
                    vis[up]=true;
                }
                if(vis.find(down)==vis.end()){
                    q.push({down,step+1});
                    vis[down]=true;
                }   
            }
        }
        return -1;

    }
};