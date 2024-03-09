int Solution::solve(vector<int> &a, int m) {
    int cnt=0,cur_xor=0;
    int n=a.size();
    unordered_map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<n;i++){
        cur_xor^=a[i];
        if(mp.find(cur_xor^m)!=mp.end()){
            cnt+=mp[cur_xor^m];
        }
        mp[cur_xor]++;
        // mp[cur_xor^m]++;
    }
    return cnt;
}