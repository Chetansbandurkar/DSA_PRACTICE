class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s="";
        bool f=false;
        for(int i=0;i<word.size();i++){
            s+=word[i];
            if(word[i]==ch){
                f=true;
                break;
            }
        }
        int v=s.size();
        if(!f) return word;
        for(int i=0;i<v/2;i++){
            swap(word[i],word[v-i-1]);
        }
        return word;
    }
};