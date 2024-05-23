class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            int x1 = 0;
            int x2 = 0;
            while (i < n1 && v1[i] != '.') {
                x1 = x1 * 10 + (v1[i] - '0');
                i++;
            }
            while (j < n2 && v2[j] != '.') {
                x2 = x2 * 10 + (v2[j] - '0');
                j++;
            }
            if (x1 < x2)
                return -1;
            if (x1 > x2)
                return 1;
            i++;
            j++;
        }
        int x1 = 0, x2 = 0;
        while (i < n1) {
            if (v1[i] != '.')
                x1 = x1 * 10 + (v1[i] - '0');
            if (x1 > 0)
                return 1;

            i++;
        }
        while (j < n2) {
            if (v2[j] != '.')
                x2 = x2 * 10 + (v2[j] - '0');
            if (x2 > 0)
                return -1;

            j++;
        }

        return 0;
    }
};