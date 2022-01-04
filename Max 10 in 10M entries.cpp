/*
Problem : Find max 10 numbers in a list having 10M entries.
*/

Solution:
vector<int> solve(vector<int> v, long long int n)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(v[i]);
        if(pq.size()>10) 
        pq.pop();
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
    }
    return ans;
}

Time Complexity : O(N)

Space Complexity : Constant space , a priority queue of size 10.
