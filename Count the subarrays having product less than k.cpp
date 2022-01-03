/*
Problem :
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
*/

Solution :
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(n==0)
            return 0;
        //p stores the product of the current subarray
        long long p=1;
        int start=0;
        int end=0;
        int count=0;
        
        while(end<n)
        {
            p=p*a[end];
            while(start<=end && p>=k)
            {
                p=p/a[start];
                start++;
            }
            if(p<k)
            {
                 //Each maximum window [i, j] can generate j - i + 1 valid subarrays, 
                // so we need to add j - i + 1 to the answer.
                count+=(end-start+1);
            }
            end++;
        }
       return count;
}


Time Complexity : O(N)

Space Complexity : O(1)
