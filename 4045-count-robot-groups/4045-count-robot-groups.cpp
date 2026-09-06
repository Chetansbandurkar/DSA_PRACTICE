class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        pair<int, int> last;
        int n = speed.size();
        last = {speed[n - 1], position[n - 1]};
        int grps = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (speed[i] > last.first || last.second - position[i] <= distance) {
                last = {last.first, position[i]};
            } else {
                grps++;
                last = {speed[i], position[i]};
            }
        }

        return grps;
    }
};