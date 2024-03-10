class Solution {
public:
    int findMin(vector<int>& a) {
        int l=0,h=a.size()-1;
        while(l<h){
            int md=(l+h)/2;
            if(a[md]>=a[l] && a[md]>=a[h]){
                l=md+1;
            }else{
                h=md;
            }
        }

        return a[l];
    }
};

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 