class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n,0), ans;
        vector<int> adj[n];
        queue<int> q;
        
        //create adjacency list
        for(auto e : edges) {
            degree[e[0]]++; //also update the
            degree[e[1]]++; //degree of each node
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<n; i++) {
            if(degree[i] == 1) { //all the nodes having degree 1
                q.push(i); //should be pushed in queue
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while(size--) {
                auto curr_node = q.front();
                q.pop();
                temp.push_back(curr_node);
                
                for(auto child : adj[curr_node]) {
                    degree[child]--;
                    if(degree[child] == 1) {
                        q.push(child);
                    }
                }
            }
         ans = temp; //always update ans with the last level of nodes removed
        }
        if(ans.empty()) { //edge case
            ans.push_back(0); //if only one node is present
        }
     return ans;
    }
};