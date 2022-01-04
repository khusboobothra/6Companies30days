/*
Problem :
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
*/

Solution :
string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        stack<int>st;
        int num=1;
        for(auto it:S)
        {
            if(it=='D')
            {
                st.push(num);
                num++;
            }
            else
            {
                st.push(num);
                num++;
                while(!st.empty())
                {
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
                    ans+=to_string(st.top());
                    st.pop();
        }
        return ans;
    }

Time Complexity : O(N)

Space complexity : O(1)
