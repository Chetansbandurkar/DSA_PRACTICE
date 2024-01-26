class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, num = 0;
        //    spaces hata pahle
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // sign check kr bhai
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign=s[i]=='+'?1:-1;
            i++;
        }
    //   for th case "lakshya3435243ram123" 
    // we will only hacve to return thre 3435243 return 
        while(i<s.size() && isdigit(s[i])){
            // int mx->val=2147483647<<<at last 4 2nd co
            // 2nd condition is checking for the 47 if 2.....4==num && s[i]>7 the definitely the \
            // int... flow occure 
            // 1st condition is checking for the  i=2....4<num to koi he hi nhi ise les no so 
            // return 
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')){
                return sign==-1?INT_MIN:INT_MAX;
            }
            num=num*10+(s[i]-'0');
            i++;
        }
// idhar bhi dekh leyta sign konsa dena he 
        return num*sign;
    }
};