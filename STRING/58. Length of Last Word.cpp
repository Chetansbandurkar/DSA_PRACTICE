class Solution {
public:
    int lengthOfLastWord(string s) {
        string t ="";
        vector<string>tmp;
        for(int i=0;i<s.size();i++){
            // cout<<s[i]<<endl;
            if(s[i]==' '&&!t.empty()){
                // cout<<t<<endl;
                tmp.push_back(t);
                t="";
            }else if(s[i]!=' '){
                t+=s[i];
            }
        }
        if(!t.empty()){
            // cout<<t<<endl;
            tmp.push_back(t);
        }
        return tmp.back().size();
    }
};