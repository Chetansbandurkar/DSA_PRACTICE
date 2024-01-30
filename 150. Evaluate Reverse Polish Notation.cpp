class Solution {
public:
    int evalRPN(vector<string>& s) {
        int ans=0;
        stack<int>st;
        // to_string bhi function use kr sakta 
        // tu string ka bhi stack bana sakta
        // stoi or stoll ka bhi use kr sakta
        for(int i=0;i<s.size();i++){
            if(s[i]=="+"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b+a);
            }
            else if(s[i]=="*"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b*a);

            }else if(s[i]=="-"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b-a);
            }else if(s[i]=="/"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                st.push(b/a);
            }
            else {
                st.push(stoi(s[i]));
            }
        }

        return st.top();
    }
};