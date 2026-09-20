class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& v) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(),v.end());
        pq.push(v[0][1]);
        long long ans = 0;
        for (int i = 1; i < v.size(); i++) {
            while (!pq.empty() && pq.top() < v[i][0]) {
                pq.pop();
            }
            ans += pq.size();
            pq.push(v[i][1]);
        }

        return ans;
    }
};