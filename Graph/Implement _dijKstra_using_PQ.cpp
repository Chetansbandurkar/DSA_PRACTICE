//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // DEclre the min heap
        // pair<DIST,NODE>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(V,INT_MAX);
        // insert the sourse node with dist,node
        // as the dist from the src to src will be 0
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                
                if(dist[adjNode]>dis+edgeWeight){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dis+edgeWeight,adjNode});
                }
            }
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends




class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int>ans;
        // int n=edges.size();
//         {v,length}
        vector<pair<int,int>>a[n];
        for(auto it:edges){ 
           a[it[0]].push_back({it[1],it[2]});
           a[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,1e9);
        set<pair<int,pair<int,int>>>st;//-><dist,node>
        dist[0]=0;
//         val,node, dispt
        st.insert({0,{0,1}});
        int cnt=1;
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second.first;
            // cout<<node<<" ";
            int dsp=it.second.second;
            // cout<<dis<<" "<<node<<" "<<dsp<<endl;
            st.erase(it);
            for(auto it:a[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                // cout<<edgeWeight<<" "<<adjNode<<endl;
                if(dis+edgeWeight<dist[adjNode] && dsp+1<=disappear[adjNode]){
                    if(dist[adjNode]!=1e9)
                    st.erase({dist[adjNode],{adjNode,dsp}});
                    // update bhi kr le bhai adNOde side
                    dist[adjNode]=dis+edgeWeight;
                    // cout<<dist[adjNode]<< " ";/
                    st.insert({dist[adjNode],{adjNode,dsp+1}});
                }
                
            }
        }
        for(int i=0;i<n;i++) { 
        cout<<dist[i]<< " ";
        }
        return dist;
        
        
    }
};