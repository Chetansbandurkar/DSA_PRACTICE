class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &a)
    {
        vector<string> ans;
        vector<set<int>> v[n];
        for (int i = 0; i < a.size(); i++)
        {
            string s = s[i];
            for (int j = 0; j < s.size(); j++)
            {
                string tmp = "";
                for (int k = i; k < s.size(); k++)
                {
                    tmp += s[k] ;
                    v[i].insert(tmp);
                }
            }
        }
        int i = 0;
        int ln=INT_MAX;
        for (int i = 0; i < n; i++)
        {   
            for (auto it : v[i])
            {
                bool f=true;
                string a;
                for (int j = 0; j < n; j++)
                {
                    if(i!=j && v[j].find(it)!=v[j].end()){
                        f=false;
                        break;
                    }
                }
                if(f){
                    if(ln>=it.length()){
                        ln=it.length();
                        a=*it;
                    }
                }
            }
            if(a)
            ans.push_back(a);
        }

        return ans;
    }
};