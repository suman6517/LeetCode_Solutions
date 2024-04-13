class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
        {
            return false;
        }
        // unordered_map<char ,int>m1;
        // unordered_map<char,int>m2;

        // for(auto it1 : s)
        // {
        //     m1[it1]++;

        // }
        // for(auto it2 : t)
        // {
        //     m2[it2]++;

        // }

        // for(int i =0 ; i<m1.size() ; i++)
        // {
        //     if (m1[i] != m2[i])
        //     {
        //         return false;
        //     }
        // }
        // return true;

        unordered_map<char , int> count;

        for (auto it1: s)
        {
            count[it1] ++;
        }

        for (auto it2 :t)
        {
            if (count.find(it2) == count.end() || count[it2] == 0)
            {
                return false;
            }
            count[it2]--;
        }

        return true;


    }
};