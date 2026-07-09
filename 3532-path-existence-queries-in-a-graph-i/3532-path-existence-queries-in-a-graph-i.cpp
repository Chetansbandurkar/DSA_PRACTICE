class DSU
{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node){
        if(node==parent[node]) return node;

        return findParent(parent[node]);
    }

    void unite(int x, int y)
    {
        int px = findParent(x);
        int py = findParent(y);
        if(px==py) return ;

        if(size[px]>size[py]){
            size[px]+=size[py];
            parent[py]=px;
        }
        else{
            size[py]+=size[px];
            parent[px]=py;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        DSU dsu(n);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                dsu.unite(i-1,i);
            }
        }

        vector<bool>ans(q.size(),false);
        int ind = 0;
        for(auto it: q){
            int x = it[0];
            int y = it[1];
            if(dsu.findParent(x)==dsu.findParent(y)){
                ans[ind]=true;
            }
            ind++;
        }

        return ans ;
    }
};