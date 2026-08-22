class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        // We will BS on small vect
        if (n > m) {
            return findMedianSortedArrays(b, a);
        }

        int leftSideRequired = (n + m + 1) / 2;
        int l = 0;
        int h = n; //?? why n not n-1

        while (l <= h) {
            // for the small array
            int mid1 = (l + h) >> 1;
            // second part of large array
            int mid2 = leftSideRequired - mid1;

            int leftA = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int rightA = (mid1 >= n ? INT_MAX : a[mid1]);
            int leftB = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int rightB = (mid2 >= m ? INT_MAX : b[mid2]);

            // chech if we can merge both the cut parts of the array
            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2 == 1) {
                    return max(leftA, leftB);
                }

                int x = max(leftA, leftB);
                int y = min(rightA, rightB);

                return (x + y) / 2.0;
            } else if (leftA > rightB) {
                h = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }

        return 0.0;
    }
};