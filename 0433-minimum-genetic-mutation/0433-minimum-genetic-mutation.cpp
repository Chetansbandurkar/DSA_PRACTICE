class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> canUsed(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        set<string> seen;
        seen.insert(startGene);
        int ans = 0;
        char a[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string str = q.front();
                q.pop();
                if (str == endGene)
                    return ans;
                for (int i = 0; i < str.size(); i++) {
                    char cc = str[i];
                    for (int c = 0; c < 4; c++) {
                        str[i] = a[c];
                        if (canUsed.count(str) && !seen.count(str)) {
                            q.push(str);
                            seen.insert(str);
                        }
                        str[i] = cc;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};