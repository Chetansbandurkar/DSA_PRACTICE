class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        string ans ;
        while(!pq.empty())
        {
            auto [cnt , c] = pq.top();
            pq.pop();
            int n = ans.size();

            if(ans.size()>=2 && ans[n-1]==c && ans[n-2]==c){
                if(pq.empty()) break;
                auto [cnt2 , c2]= pq.top();
                pq.pop();

                ans.push_back(c2);
                cnt2--;

                if(cnt2>0){
                    pq.push({cnt2,c2});
                }

                pq.push({cnt,c});

            }
            else{
                ans.push_back(c);

                cnt--;
                if(cnt>0) pq.push({cnt, c});
            }
        }


        return ans ;
    }
};