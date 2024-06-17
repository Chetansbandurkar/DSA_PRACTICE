class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
        unordered_set<string>s(dict.begin(),dict.end());

        string ans,word;
        bool isFound=0;
        for(char c:sen){
            if(c!=' '){
                word+=c;
                if(!isFound && s.count(word)){
                    ans+=word;
                    isFound=1;
                }
            }
            else{
                if(!isFound)ans+=word;
                ans+=' ';
                word="";
                isFound=0;
            }
        }

        if(!isFound){
            ans+=word;
        }

        return ans;
    }
};