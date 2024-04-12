class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
        {
            return false;
        }
        map<char ,int>m1;
        map<char,int>m2;

        // for(auto it1 : s)
        // {
        //     m1[it1]++;

        // }
        // for(auto it2 : s)
        // {
        //     m2[it2]++;

        // }
         for(int i = 0; i < s.size(); i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }

        for(int i =0 ; i<m1.size() ; i++)
        {
            if (m1[i] != m2[i])
            {
                return false;
            }
        }
        return true;


    }
};