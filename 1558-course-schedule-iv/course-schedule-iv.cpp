class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        unordered_map<int,unordered_set<int>>mp;
        vector<int>indegree(numCourses,0);
        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                mp[it].insert(node);
                for(auto pre:mp[node]){
                    mp[it].insert(pre);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<bool>result;
        for(auto q:queries){
            result.push_back(mp[q[1]].count(q[0]));
        }
        return result;
    }
};