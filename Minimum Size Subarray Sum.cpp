/*
Problem :
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum 
is greater than or equal to target. If there is no such subarray, return 0 instead.

https://leetcode.com/problems/minimum-size-subarray-sum/
*/

Solution :
bool is_valid(vector<int>&nums,int target,int len)
    {
        int sum=0,n=nums.size();
        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
        }
        if(sum>=target)
        {
            return true;
        }
        int left=0,right=len-1;
        while(right+1<n)
        {
            sum+=(nums[right+1]-nums[left]);
            if(sum>=target)
            {
                return true;
            }
            right++;
            left++;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size(),ans=INT_MAX,start=0,end=n;
        while(start<=end)
        {
            int mid=start+((end-start)/2);
            // check wheather there is a subarray of length = mid, with sum >=target
            if(is_valid(nums,target,mid))
            {
                // If there is a valid subarray with sum>=target then mid can be a potential answer so store this result and look for a smaller subarray (by making end=mid-1)
                ans=min(ans,mid);
                end=mid-1;
            }
            // If there is no valid subarray with length = mid that means we've to increase the subarray size to get a sum>=target. So increment the length by making start=mid+1;
            else
            {
                start=mid+1;
            }
        }
        // If ans still remains INT_MAX that means there is no valid subarray so return 0
        // otherwise return the answer.
        return ans==INT_MAX?0:ans;
    }

Time Complexity : O(N*log N)

Space Complexity : O(1)
