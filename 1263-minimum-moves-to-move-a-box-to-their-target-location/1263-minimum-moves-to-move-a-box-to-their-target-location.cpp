class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool inside(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
    bool canWalk(int x, int y, int srcX, int srcY, vector<vector<int>>& vis,
                 vector<vector<char>>& g) {
        if (x == srcX && y == srcY)
            return true;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (inside(nx, ny) && g[nx][ny] != '#' && !vis[nx][ny] &&
                canWalk(nx, ny, srcX, srcY, vis, g))
                return true;
        }

        return false;
    }
    int minPushBox(vector<vector<char>>& g) {

        n = g.size();
        m = g[0].size();

        int box_x, box_y, person_x, person_y, t_x, t_y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'T') {
                    t_x = i;
                    t_y = j;
                } else if (g[i][j] == 'B') {
                    box_x = i;
                    box_y = j;
                } else if (g[i][j] == 'S') {
                    person_x = i;
                    person_y = j;
                }
            }
        }

        set<vector<int>> seen; // vist already
        queue<vector<int>> q;  // bfs
        q.push({box_x, box_y, person_x, person_y});
        seen.insert({box_x, box_y, person_x, person_y});
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                box_x = q.front()[0], box_y = q.front()[1],
                person_x = q.front()[2], person_y = q.front()[3];
                q.pop();

                if (box_x == t_x && box_y == t_y) {
                    return ans;
                }
                g[box_x][box_y] = '#';
                for (int i = 0; i < 4; i++) {
                    int newBox_x = dx[i] + box_x;
                    int newBox_y = dy[i] + box_y;
                    int newPerson_x = box_x - dx[i];
                    int newPerson_y = box_y - dy[i];
                    vector<int> cur(
                        {newBox_x, newBox_y, newPerson_x, newPerson_y});
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (inside(newBox_x, newBox_y) &&
                        g[newBox_x][newBox_y] != '#' && !seen.count(cur) &&
                        canWalk(person_x, person_y, newPerson_x, newPerson_y,
                                vis, g)) {
                        seen.insert(cur);
                        q.push(cur);
                    }
                }
                g[box_x][box_y] = '.';
            }
            ans++;
        }

        return -1;
    }
};