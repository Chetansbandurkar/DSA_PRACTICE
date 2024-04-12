class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && isupper(s[i]) && st.top()==tolower(s[i])){
                st.pop();
            }
            else if(!st.empty() && isupper(st.top()) && tolower(st.top())==s[i]){
               st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};