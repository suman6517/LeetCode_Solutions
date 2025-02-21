class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int>mapp;
        int maxLength = 0;
        int leftPointer =0;
        int rightPointer = 0;
        int length = s.length();
        
        while(rightPointer < length)
        {
            char currentChar = s[rightPointer];
            // if(mapp[s[rightPointer]] != -1)   //That Means the Character is in the Map
            // {
            //     if(mapp[s[rightPointer]] >=leftPointer)
            //     {
            //         leftPointer=mapp[s[rightPointer]]+1;
            //     }
            // }

            if(mapp.find(currentChar) != mapp.end() && mapp[s[rightPointer]] >=leftPointer)
            {
                leftPointer=mapp[s[rightPointer]]+1;
            }

            
            int length = rightPointer - leftPointer +1;
            maxLength = max(length , maxLength);
            mapp[s[rightPointer]] = rightPointer;
            rightPointer ++;
        }
        return maxLength;
        
    }
};