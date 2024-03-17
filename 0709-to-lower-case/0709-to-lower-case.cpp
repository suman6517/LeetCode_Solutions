class Solution {
public:
    string toLowerCase(string s) 
    {
       int size = s.length();
       string ans;

       for (int i =0 ; i<size; i++)
       {
        if (s[i] >='A' && s[i] <='Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
       }

       return s;   
        
    }
};