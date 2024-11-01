class Solution {
public:
    string makeFancyString(string s) 
    {
        if(s.length() <=2)
        {
            return s;
        }
        string ans ="";
        for (int i=0; i<s.length()-2; i++)
        {
            if(s[i]==s[i+1] && s[i]==s[i+2])
            {
                continue;
            }
            ans+=s[i];
        }
        ans+=s[s.length()-2];
        ans+=s[s.length()-1];
        return ans;
    }
};