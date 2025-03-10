//tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int up= grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;

                    int left= grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;

                    dp[i][j]=min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


//memoization 
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
  
    if (i == 0 && j == 0)
        return matrix[0][0]; 
    if (i < 0 || j < 0)
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j]; 
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    return dp[i][j] = min(up, left);
}


int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}

//space optimization 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        vector<int>prev(m,0);
        for(int i=0; i<n; i++){
            vector<int>curr(m,0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    curr[j]=grid[i][j];
                }
                else{
                    int up= grid[i][j];
                    if(i>0) up+=prev[j];
                    else up+=1e9;

                    int left= grid[i][j];
                    if(j>0) left+=curr[j-1];
                    else left+=1e9;

                    curr[j]=min(up, left);
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }
};