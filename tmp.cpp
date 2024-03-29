class Solution {
public:
    int minOperations(int k) {
        priority_queue<int>pq;
        vector<int>ans;
        ans.push_back(freq[0]);
        pq.push(freq[0]);
        for(int i=1;i<freq.size();i++){
            if(freq[i]<0){
                int val=abs(freq[i]);
                while(!pq.empty() && val){
                    val-=pq.top();pq.pop();
                }
            }
            pq.push(freq[i]);
            ans.push_back(pq.top());
            
        }
    }
};