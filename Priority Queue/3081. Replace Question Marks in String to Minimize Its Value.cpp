class Solution {
public:
    string minimizeStringValue(string s) {
        string ans = "";
        priority_queue<pair<int, char>, vector<pair<int, char>>,
                       greater<pair<int, char>>>
            pq;
        map<char, int> mp;
        // have to insert the  less freq char 
        // then have to sort the string which we wan to insert insted of the 
        // '?' so this will make the string lexicographicaly small
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp.find(c) != mp.end()) {
                pq.push({mp[c], c});
            } else {
                pq.push({0, c});
            }
        }
        string st = "";
        // sort this so cost will remain same and the string will be sorted 
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                char c = pq.top().second;
                int frq = pq.top().first;
                pq.pop();
                st += c;
                pq.push({frq + 1, c});
            }
        }
        sort(st.begin(), st.end());
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                ans += st[k++];
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
