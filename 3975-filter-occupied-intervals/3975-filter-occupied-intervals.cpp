class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oc, int fs,
                                                int fe) {
        vector<vector<int>> ans;
        sort(oc.begin(), oc.end());
        int ls = oc[0][0];
        int le = oc[0][1];
        for (int i = 1; i < oc.size(); i++) {
            if (oc[i][0] > le + 1) {
                ans.push_back({ls, le});
                ls = oc[i][0];
                le = oc[i][1];
            } else {
                le = max(le, oc[i][1]);
            }
        }

        ans.push_back({ls, le});
        vector<vector<int>> a;
        for(auto it:ans){
            cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
        }
        cout<<endl;
        cout<<endl;
        for (auto& it : ans) {
            if(it[0]>=fs && it[0]<=fe && it[1]>=fs && it[1]<=fe) continue;
            else if (fe >= it[0] && fe <= it[1] && fs >= it[0] && fs <= it[1]) {
                int u, v;
                if (it[0] == fs)
                    u = fs - 1, v = fs - 1;
                else
                    v = fs - 1, u = it[0];
                if(u>0 && u>=it[0])
                a.push_back({u, v});
                if (it[1] == fe)
                    u = fe + 1, v = fe + 1;
                else
                    v = it[1], u = fe + 1;
                if(u<=it[1])
                a.push_back({u, v});

             continue;
            } else if (fe >= it[0] && fe <= it[1])
                it[0] = min(it[1], fe + 1);
            else if (fs >= it[0] && fs <= it[1])
                it[1] = max(it[0], fs - 1);
            a.push_back(it);
        }
        return a;
    }
};