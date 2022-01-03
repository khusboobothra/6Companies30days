/*
Problem : Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
By convention, 1 is included. Write a program to find Nth Ugly Number.

https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
*/

Solution :
 int nthUglyNumber(int n) {
    vector<int>dp(n);
        dp[0]=1;
        
        int p1=0;
        int p2=0;
        int p3=0;
        
        for(int i=1;i<n;i++)
        {
            int two_multiple=dp[p1]*2; //1*2
            int three_multiple=dp[p2]*3; //1*3
            int five_multiple=dp[p3]*5; //1*5
            
            dp[i]=min(two_multiple,min(three_multiple,five_multiple));
            
            if(dp[i]==two_multiple)
                p1++;
            if(dp[i]==three_multiple)
                p2++;
            if(dp[i]==five_multiple)
                p3++;
        }
        return dp[n-1];
    }



Time Complexity : O(N)

Space Complexity : O(N)
