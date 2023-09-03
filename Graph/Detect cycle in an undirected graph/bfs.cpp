class Solution {
  public:
    bool bfs(int source, vector<int> adj[], vector<int> &visited){
        queue<pair<int,int>> q;
        q.push({source, -1});
        visited[source] = true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode : adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = true;
                    q.push({adjNode, node});
                }else if(parent != adjNode){
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        bool res = false;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                // below commented line also worked.
                // res = res || bfs(i, adj, visited);
                if(bfs(i, adj, visited)){
                    return true;
                }
            }
        }
        return res;
    }
};



// TC = O( V + 2*E) + O(V)
// Twice of edge because for every node, we are traversing all its adjacent node.
// Summation of all adjacent node is summation of all degrees =  2*E

// SC = O(V)

  
