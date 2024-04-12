class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        string  ans="";
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')ans+=s[i];
        }

        return ans;
    }
};