class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int ,int>mp;
        unordered_map<int,int>pairs;
        for(auto it:planks)
        {
            mp[it]++;
        }
        vector<int>v;
        for(auto it:mp)
        {
            v.push_back(it.first);
        }

        int m = v.size();

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int sm = v[i]+v[j];
                if(i==j){
                    pairs[sm]+=(mp[v[i]]/2);
                }
                else{
                    pairs[sm]+=(min(mp[v[i]],mp[v[j]]));
                }
            }
        }
        int ans = 0;
        for(auto &[c,d]:pairs){
            ans = max(ans, d+mp[c]);
        }
        for(auto &[c,d]:mp){
            ans = max(ans, d);
        }

        return ans ;
    }
};