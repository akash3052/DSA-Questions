class Solution {
  public:
    void dfs(int u, vector<int> adjList[], vector<int> &visited){
        visited[u] = true;
        for(auto v : adjList[u]){
            if(!visited[v]){
                dfs(v, adjList, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V];
        // we can also use below data structure in place of vector.
        // set<int> adjList[V] 
        // map<int, vector<int>> adjList;
        // map<int, set<int>> adjList;
        // vector<vector<int>> adjList;
        for(int i = 0; i < V; i++){
           // we can also run loop till V because we are using visited array and before each dfs call, we are checking if that node is visited or not. 
            for(int j = 0; j < i; j++){
                if(adj[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> visited(V,0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjList, visited);
            }
        }
        return cnt;
    }
};

// TC = O(v) + O(v+2*e) = O(v)
// outer loop runs v times and for each vertex dfs is called.

// SC = O(v) + O(v) = O(v)
// visited array + recursion stack space


