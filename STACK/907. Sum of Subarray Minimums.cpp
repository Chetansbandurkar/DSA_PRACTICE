class Solution {
public:
    //  get the smallest element in the right ans the left
    //  check at each index that current element is  for ehich range
    // then form the combination for left and right distant
    // in this way we will cover al the ranges for each element
    // ex 6 7 1 4 5  for 1 3l3ft
    // -> Next smallest left 3 and right 3=9 conmbinations
    // when u are emptying the stack look for the example
    // 3,3,3,3,3  (case for the NSL or NSR me only < or > rakhna padega 
    // or ek isme >= or <= rakhna padega )
    vector<int> getNSL(vector<int>& a) {
        stack<int> st;
        vector<int> res(a.size(), -1);
        for (int i = 0; i < a.size(); i++) {
            if (st.empty()) {
                res[i] = -1;
            } else {
                while (!st.empty() && a[st.top()] > a[i]) {
                    st.pop();
                }
                if (!st.empty())
                    res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }
    // next smaller right
    vector<int> getNSR(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> res(a.size(), n);
        // int n=a.size();
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                res[i] = n;
            } else {
                while (!st.empty() && a[st.top()] >=a[i]) {
                    st.pop();
                }

                if (!st.empty())
                    res[i] = st.top();
            }

            st.push(i);
        }

        return res;
    }
    int sumSubarrayMins(vector<int>& a) {
        vector<int> NSL = getNSL(a);
        vector<int> NSR = getNSR(a);

        // for (auto i : NSL)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : NSR)
        //     cout << i << " ";

        int M=1e9+7;
        long long  sum=0;
        for(int i=0;i<a.size();i++){
            // left side for till wich the cur element will bw small
            long long  d1=i-NSL[i];
            // Right side  till which the cur element will be small;
            long long  d2=NSR[i]-i;

            long long tot_ways_for_cur_ele=d1*d2;

            long long sum_of_i_in_tot_ways=(tot_ways_for_cur_ele)*a[i];
            sum=(sum+sum_of_i_in_tot_ways)%M;
            
        }
        return sum;
    }
};