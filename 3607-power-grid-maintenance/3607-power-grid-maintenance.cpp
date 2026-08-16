class DSU {
public:
    vector<int> s, p;
    DSU(int n) {
        s.resize(n + 1);
        p.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            s[i] = 1;
            p[i] = i;
        }
    }
    int findP(int x) {
        if (x == p[x])
            return x;

        return p[x] = findP(p[x]);
    }

    bool isSame (int x, int y)
    {
        return findP(x)==findP(y);
    }
    void unite(int x, int y) {
        int px = findP(x);
        int py = findP(y);

        if (px == py)
            return;

        if (s[px] > s[py]) {
            s[px] += s[py];
            p[py] = px;
        } else {
            s[py] += s[px];
            p[px] = py;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int cc, vector<vector<int>>& c, vector<vector<int>>& q) {

        map<int,set<int>>mp;
        DSU dsu(cc);
        for(auto it:c){
            dsu.unite(it[0],it[1]);
        }

        for(int i=1;i<=cc;i++){
            mp[dsu.findP(i)].insert(i);
        }
        
        vector<int>off(cc+1, false);
        vector<int>ans;
        for(auto it: q){
            if(it[0]==2){
                off[it[1]]= true;
                auto & st = mp[dsu.findP(it[1])];
                st.erase(it[1]);
            }else if(it[0]==1 && !off[it[1]]){
                ans.push_back(it[1]);
            }else{
                if(!mp[dsu.findP(it[1])].empty()){
                    ans.push_back(*mp[dsu.findP(it[1])].begin());
                }
                else{
                    ans.push_back(-1);
                }
            }
        }

        return ans ;
    }
};