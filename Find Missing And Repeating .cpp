/*
Problem : 
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
*/

/*
Approach: 
Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is 
already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.
*/

Solution :
int *findTwoElement(int *arr, int n) {
        // code here
        int* res=new int[2];
        int repeating=0;
        int missing=0;
        
        for(int i=0;i<n;i++)
        {
            int index=abs(arr[i])-1;
            if(arr[index]>0)
            arr[index]=-1*arr[index];
            else
            repeating=abs(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            missing=i+1;
        }
        res[0]=repeating;
        res[1]=missing;
        return res;
    }

Time Complexity : O(N)

Space Complexity : O(1)
