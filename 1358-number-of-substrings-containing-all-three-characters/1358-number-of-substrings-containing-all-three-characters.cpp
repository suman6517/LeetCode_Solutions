class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int count =0;
        int lastseen[3] =-1;
        for(int i=0; i<s.size() ; i++)
        {
            lastseen[s[i]-'a'] =i;
            
            if(lastseen[0]!=-1 &&lastseen[0]!=-1 && lastseen[0]!=-1)
            {
                count = count + (1+min(lastseen[0],lastseen[1],lastseen[2]))
            }

        }
        return count;
    }
};