/*
Problem :
Given a string, Your task is to complete the function encode that returns the run length encoded string for the given string. Eg : if the input string is “wwwwaaadexxxxxx”, then 
the function should return “w4a3d1e1x6″.

You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
*/

Solution :
string encode(string src)
{     
  //Your code here 
  int n = src.length();
  string res="";
    for (int i = 0; i < n; i++) {
 
        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && src[i] == src[i + 1]) {
            count++;
            i++;
        }
 
        // Print character and its count
        res+=(src[i]+to_string(count));
    }
    return res;
}     

Time Complexity : O(N)

Space Complexity :O(N)
