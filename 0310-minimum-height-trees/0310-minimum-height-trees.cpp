class Solution {
public:
//  Leaf Nodes ??
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<int>ind(n,0);
        vector<vector<int>>g(n);
        for(auto it: e)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            ind[it[0]]++;
            ind[it[1]]++;
        }

        queue<int>q;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(ind[i]==1){
                q.push(i);
                ans.push_back(i);
            }
        }
        // vector<int>ans;
        while(!q.empty()){

            int sz = q.size();
            vector<int>temp;
            while(sz--){
                int node = q.front();
                temp.push_back(node);
                q.pop();

                for(auto it:g[node]){
                    ind[it]--;
                    if(ind[it]==1){
                        q.push(it);
                        // temp.push_back()
                    }
                }
            }

            ans = temp;
        }
        if(ans.empty()) return {0};

        return ans ;
    }
};