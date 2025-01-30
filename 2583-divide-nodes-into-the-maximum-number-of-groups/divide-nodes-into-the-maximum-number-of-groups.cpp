class Solution {
    vector<int>color;
    vector<vector<int>>adj;
    int n;
    bool dfs(int node,int c,vector<int>&component){
        color[node]=c;
        component.push_back(node);
        for(auto it: adj[node]){
            if(color[it]==c) return false;
            if(color[it]==-1 && !dfs(it,1-c,component)){
                return false;
            }
        }
        return true;
    }
    int maxgroups(vector<int>&component){
        int maxdepth=0;
        for(auto it:component){
            vector<int> depth(n,-1);
            queue<int>q;
            q.push(it);
            depth[it]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(depth[it]==-1){
                        depth[it]=depth[node]+1;
                        maxdepth=max(maxdepth,depth[it]);
                        q.push(it);
                    }
                }
            }
        }

        return maxdepth+1;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n=n;
        color.assign(n,-1);
        adj.resize(n);
        for(auto e:edges){
            int u=e[0]-1;
            int v=e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>component;
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                component.emplace_back();
                if(!dfs(i,0,component.back())){
                    return -1;
                }
            }
        }
        int total=0;
        for(auto comp:component){
            total+=maxgroups(comp);
        }
        return total;
    }
};