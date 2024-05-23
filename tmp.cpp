class Solution
{
public:
    
    int maxPointsInsideSquare(vector<vector<int>> &p, string s)
    {
        vector<pair<int, string >> v;
        int i = 0;
        map<int,char>mp;
        for (auto it : p)
        {
            int val=it[0]*it[0]+it[1]*it[1];

            if(abs(it[0])==abs(it[1]))
            {
                string t="s"+s[i];
                v.push_back({val,t});
            }
            else{
                string t="n"+s[i];
                v.push_back({val,t});
            }
            i++;
            
        }
        sort(v.begin(),v.end());
        int cnt=0;
        int ans=0;
        for(auto it:v){
            auto st=it.second;
            char f=st[0];
            char se=st[1];

            if(mp[se]>1){
                cnt--;
            }
            else if(f=='s'){
                ans=max(ans,cnt);
                cnt++;
            }
            
            mp[se]++;
        }

        return ans;
    }
};