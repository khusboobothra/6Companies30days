/*
Problem :
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26

You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, 
extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/
*/

RECURSIVE Solution would have Time Complexity of  O(2^N) as at each step we will have two options : select single digit or select double digit

OPTIMIZED(MEMOIZED) Solution :
vector<int> dp;

    int recur(string &s, int i){
        if(s.size() == 0){
            return 0;
        }
        if(s.size() == i){
            return 1;
        }
        if(s[i] == '0'){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int s1 = 0, s2 = 0;
        if(s[i] >= '1' && s[i] <= '9'){
            s1 = recur(s, i+1);
        }
        if(s[i] == '1' && s[i+1] >= '0' && s[i+1] <= '9' || s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6' ){
            s2 = recur(s, i+2);
        }
        dp[i] = (s1 + s2)%1000000007;
        return dp[i];
    }
    
		int CountWays(string str){
		    // Code here
		    dp = vector<int>(str.size()+1, -1);
		    return recur(str,0);
		}

Time Complexity : O(N)

Space Complexity : O(N)
