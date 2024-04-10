//recursive + memoization solution
class Solution{
    private:
    int solve(int n, vector<int> &dp){
        //base case
        if(n==0)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int ans=n;
        for(int i=1; i*i<=n; i++){
            int temp=i*i;
            ans=min(ans, 1+solve(n-temp, dp));
        }
        dp[n]=ans;
        return dp[n];
    }
	public:
	int MinSquares(int n)
	{
	    vector<int>dp(n+1, -1);
	    return solve(n, dp);
	}
};

//tabulaton form
class Solution{
    private:
  	int solveTab(int n){
	    vector<int> dp(n+1, INT_MAX);
	    
	    dp[0] = 0;
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j*j<=i; j++){
	            int temp = j*j;
	            
	            if(i-temp >= 0)
	                dp[i] = min(dp[i], 1 + dp[i-temp]);
	        }
	    }
	    
	    return dp[n];
	}
	public:
	int MinSquares(int n)
	{
	    
	    return solveTab(n);
	}
};