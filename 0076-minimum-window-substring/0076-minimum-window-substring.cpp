class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lengthS = s.length();
        int lengthT = t.length();
        int right = 0 , left =0 , minLength = INT_MAX , count = 0 , startingIndex = -1;
        unordered_map<char,int>mpp;
        for(int i =0 ; i<lengthT ; i++)
        {
            mpp[t[i]] ++ ;
        }

        while(right < lengthS)
        {
            if(--mpp[s[right]] ==0)
            {
                count++;
            }
            while(count == lengthT)
            {
                if(right-left +1 < minLength) 
                {
                    minLength = rigth - left+1;
                }
                if(++mpp[s[left]] >0)
                {
                    count --;
                }
                left++;
            }
        }
        return startingIndex == -1 ?"": s.substr(startingIndex ,lengthT);
    }
};