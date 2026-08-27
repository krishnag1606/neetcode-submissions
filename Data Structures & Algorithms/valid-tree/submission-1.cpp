class Solution {
public:
    bool validTree(int n, vector<vector<int>>& nums) {
        if(nums.size() > n-1) return false;

        vector<vector<int>> adj(n);
        for(auto &e: nums){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int nbr: adj[cur]){
                if(vis[nbr]) continue;
                vis[nbr] = true;
                q.push(nbr);
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};
