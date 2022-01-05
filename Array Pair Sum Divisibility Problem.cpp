/*
Problem :
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
*/

Solution :
bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[((i%k)+k)%k]++;
        }
        if(mp[0]%2 != 0)
        return false;
        for(int i=1;i<k;i++)
        {
            if(mp[i] != mp[k-i])
            return false;
        }
        return true;
    }

Time Complexity : O(N)

Space Complexity : O(N)
