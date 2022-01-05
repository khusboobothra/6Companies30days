/*
Problem :
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]

https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
*/

Solution :
string decode(string &s,int &idx)
    {
        int times=0;
        string word="";
        
        while(idx<s.length())
        {
            if(s[idx]>='0' && s[idx]<='9')
            times=times*10+(s[idx]-'0');
            
            else if(s[idx]=='[')
            {
                idx++;
                string temp=decode(s,idx);
                while(times--)
                word=word+temp;
                times=0;
            }
            else if(s[idx]==']')
                return word;
            else
                word=word+s[idx];
            idx++;
        }
        return word;
    }
    string decodedString(string s){
        // code here
        int idx=0;
        return decode(s,idx);
    }

Time Complexity : O(|s|)

Space Complexity : O(|s|)
