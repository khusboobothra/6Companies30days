/*
Problem :
M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at 
adjacent positions starting from K.

https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1
*/

Solution :
int findPosition(int N , int M , int K) {
        // code here
        if(N==1)
        return 1;
  
        return (M%N)+(K-1)==N?(M%N)+(K-1):((M%N)+(K-1))%N;
    }

Time Complexity : O(1)

Space Complexity : O(1)
