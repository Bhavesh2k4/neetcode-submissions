class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        vector<int> ans;
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        int c=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            c++;
            for(int x:adj[top]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if(c==numCourses){
            return ans;
        }
        return {};
    }
};
