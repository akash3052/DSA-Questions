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

// Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and 
// inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

// Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.


