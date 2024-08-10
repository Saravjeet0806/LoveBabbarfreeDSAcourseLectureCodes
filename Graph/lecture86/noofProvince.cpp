class Solution {
public:
    void dfs(int node, vector<vector<int>> & isConnected, vector<bool>&visited){
        visited[node]=true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberofComponents=0;
        vector<bool>visited(n);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                numberofComponents++;
                dfs(i, isConnected, visited);
            }
        }
        return numberofComponents;
    }
};