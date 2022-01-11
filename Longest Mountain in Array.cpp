/*
Problem :
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

https://leetcode.com/problems/longest-mountain-in-array/
*/

Solution :
 int longestMountain(vector<int>& arr) {
        int n=arr.size();
      
        */
        /*we can find peak of the mountains at index 1,2,3,4,...,n-2 not at 0th and n-1th index becuse 0th index does not have a left neighbour to form a mountain and n-1th 
        index does not have a right neighbour to form a mountain
        */
        
        int max_length = 0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) //PEAK CONDITION
            {
                int start_root = i;
                int end_root = i;
                while( start_root>0 && arr[start_root] > arr[start_root-1])
                {
                    start_root--; //getting start root
                    
                }
                while( end_root<n-1 && arr[end_root] > arr[end_root+1] )
                {
                    end_root++; //getting end root
                }
                max_length = max(max_length,(end_root-start_root+1));
                i = end_root;
            }
        }
        return max_length;
        
    }

Time Complexity : O(N)

Space Complexity : O(1)
