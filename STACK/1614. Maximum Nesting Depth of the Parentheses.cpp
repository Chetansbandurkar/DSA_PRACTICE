class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                st.push(s[i]);
            }
        }
        int res=0;
        while(!st.empty()){
            char ch=st.top();st.pop();
            if(ch==')')cnt++;
            else cnt--;

            res=max(cnt,res);
        }

        return res;
    }
};


// 2nd 
class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        // int mx=0;
        int cnt=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                cnt++;
            }
            else if(s[i]==')'){
                st.pop();
                cnt--;
            }
            res=max(res,cnt);
        }

        return res;
    }
};