class Solution
{
public:
    
    int maxPointsInsideSquare(vector<vector<int>> &p, string s)
    {
        map<int,set<int>>mp;
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto i:q){
            mp[i[1]].insert(i[0]);
            mpp[i[0]]=i[1];
            if(mp[i[1]]){
                int c=mpp[i[0]];
                auto st=mp[c];
                st.erase(i[0]);
                if(st.empty()){
                    mp.erase(i[0]);
                }
                ans.push_back(mp.size());
            }

        }

        return ans;
    }
};