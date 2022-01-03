/* 
Problem : Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array.
Look at the sample case for clarification.

https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
*/

Solution : 
vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        unordered_map<string,vector<string>>mp;
        
        for(auto s:string_list)
        {
            string t=s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>>ans(mp.size());
        int idx=0;
        for(auto it:mp)
        {
            for(auto s:it.second)
            {
                ans[idx].push_back(s);
            }
            idx++;
        }
        return ans;

Time Complexity : O(N * (L*log(L))) , where L is the length of the respective strings.

Space Complexity: O(N*L) , where N is the number of words and L is the max length among the given string lengths.
