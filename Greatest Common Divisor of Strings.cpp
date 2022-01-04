/*
Problem :
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/

/* Approach : Using the same concept we use while finding gcd of two numbers.
Suppose we have str1 shorter than str2 and they have one common divider d.
We are able to derive that str1 must be a substring of the str2.

When we subtract str1 from str2, d will be able to divide str2 - str1 (subtract) as well.

Here's the idea:
1. Subtract the shorter string from the longer one but characters must match, return "" elsewise.
2. Compare the rest of the longer string with that shorter one. And get new short and new long.
3. Repeat 1->2 until two strings are equal to each other and the recursion end.

If we have to print the sub-string after a certain position - we use s.substr(pos) -> this will print the string starting from pos+1 to s.length()-1
*/

Solution :
string gcdOfStrings(string str1, string str2) {
  
   // if the str1 = "ABCD" and str2 ="ABC" ,then str1 + str2 = "ABCDABC"  and str2 + str1 = "ABCABCD" , here both are not equal so simply return "".
        if((str1+str2)!=(str2+str1))
            return "";
  
  // if str1 == str2 return any one of the two strings , str1 = "ABC" and str2 = "ABC"
        else if(str1==str2)
            return str1;
  
  //if str1 > str2 , str1 = "ABCABC" and str2 = "ABC"
        else if(str1.length() > str2.length())
            return gcdOfStrings(str1.substr(str2.length()),str2);
  
  //if str1 < str2 , str2 = "ABCABC" and str1 = "ABC"
        else
            return gcdOfStrings(str2.substr(str1.length()),str1);
    }

Time Complexity : O(min(str1,str2))

Space Complexity : O(1) + auxillary space for recursion.
