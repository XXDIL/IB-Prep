/*
    Recursive Solution:

        int LCS(string& A, string& B, int M, int N)
        {
            if(M == 0 || N == 0) 
                return 0;
            
            if(A[M-1] == B[N-1])
                return 1 + LCS(A, B, M-1, N-1);

            return max(LCS(A, B, M-1, N), LCS(A, B, M, N-1));
        }
        
        int longestCommonSubsequence(string A, string B)
        {            
            return LCS(A, B, A.size(), B.size());
        }


    Recursive DP solution:

        vector<vector<int>> dp;
        int LCS(string& A, string& B, int M, int N)
        {
            if(M == 0 || N == 0) 
                return 0;
            
            if(dp[M][N] != -1)
                return dp[M][N];
            
            if(A[M-1] == B[N-1])
                dp[M][N] = 1 + LCS(A, B, M-1, N-1);
            else
                dp[M][N] = max(LCS(A, B, M-1, N), LCS(A, B, M, N-1));
            
            return dp[M][N];
        }
        
        int longestCommonSubsequence(string A, string B)
        {
            int M = A.size(), N = B.size();
            dp = vector<vector<int>>(M+1, vector<int>(N+1, -1));
            
            return LCS(A, B, A.size(), B.size());
        }

*/

/*
    DP Table:

        base initialization: 
            A : "" and B : "abc"
            A : "abc" and B = ""
            LCS in both cases is 0

        Propagation step:
            if the letters match -> move both back
            else 2 branches (i-1, j) and (i, j-1) 
*/
int Solution::solve(string A, string B)
{
    int M = A.size(), N = B.size();
    int dp[M+1][N+1];
    for(int i=0;i<=M;++i) dp[i][0] = 0;
    for(int i=1;i<=N;++i) dp[0][i] = 0;
    
    for(int i=1;i<=M;++i)
    {
        for(int j=1;j<=N;++j)
        {
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    return dp[M][N];
}