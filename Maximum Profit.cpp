/*
Problem :
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum
profit a person can make in at-most K transactions. 
A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
*/

Solution :
int maxProfit1(int A[],int n)
    {
        int profit=0;
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
            profit+=(A[i]-A[i-1]);
        }
        return profit;
    }
    
    int dp[501][201][2];
    int solve(int i,bool own,int k,int A[],int n)
    {
        if(i>=n)
        return 0;
        
        if(k<=0)
        return 0;
        
        if(dp[i][k][own] != -1)
        return dp[i][k][own];
        
        if(own)
        {
            int op1=A[i]+solve(i+1,0,k-1,A,n);
            int op2=solve(i+1,1,k,A,n);
            return dp[i][k][own]=max(op1,op2);
        }
        else
        {
            int op1=(-A[i])+solve(i+1,1,k,A,n);
            int op2=solve(i+1,0,k,A,n);
            return dp[i][k][own]=max(op1,op2);
        }
        return -1;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        if(K<N/2)
        {
            memset(dp,-1,sizeof(dp));
            return solve(0,0,K,A,N);
        }
        else
        return maxProfit1(A,N);
    }

Time Complexity: O(N*K)
  
Auxiliary Space: O(N*K)

