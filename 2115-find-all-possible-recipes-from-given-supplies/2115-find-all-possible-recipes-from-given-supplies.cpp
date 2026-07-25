class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rcp, vector<vector<string>>& ing, vector<string>& s) {
        unordered_map<string , vector<string>>g;
        unordered_map<string ,int>ind;
        unordered_set<string>sup(s.begin(),s.end());
        unordered_set<string>r(rcp.begin(),rcp.end());
        unordered_map<string, vector<string>>ingg;
        queue<string>q;
        vector<string>ans ;
        for(int i=0;i<rcp.size();i++){

            bool isAllIngPresent = true;

            for(auto it:ing[i]){
                if(!sup.count(it)){
                    isAllIngPresent= false;
                }
                if(r.count(it)){
                    ind[rcp[i]]++;
                    g[it].push_back(rcp[i]);
                }else {
                    ingg[rcp[i]].push_back(it);
                }
            }
            if(isAllIngPresent){
                q.push(rcp[i]);
            }
        }

        while(!q.empty()){
            auto recipe = q.front();
            q.pop();
            ans.push_back(recipe);
            for(auto it:g[recipe]){
                ind[it]--;
                bool canBe = true;
                for(auto itr :ingg[it]){
                    if(!sup.count(itr)){
                        canBe = false;
                    }
                }

                if(ind[it]==0 && canBe){
                    q.push(it);
                }
            }
        }


        return ans ;
    }
};