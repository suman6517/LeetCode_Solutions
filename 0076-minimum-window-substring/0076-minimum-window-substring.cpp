class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lengthS = s.length();
        int lengthT = t.length();
        if (lengthS < lengthT) return "";

        unordered_map<char, int> mpp;
        for (char c : t) 
        {
            mpp[c]++;
        }
        
        int left = 0, right = 0, minLength = INT_MAX, startingIndex = -1;
        int required = mpp.size();  // Number of unique characters needed

        while (right < lengthS) 
        {
            mpp[s[right]]--;
            if (mpp[s[right]] == 0) 
            {
                required--;  // Fully matched a unique character
            }

            while (required == 0)  // All unique characters are matched
            {
                if (right - left + 1 < minLength) 
                {
                    minLength = right - left + 1;
                    startingIndex = left;
                }

                if (mpp[s[left]] == 0) 
                {
                    required++;  // A fully matched character is now missing
                }
                mpp[s[left]]++;
                left++;
            }
            right++;
        }

        return startingIndex == -1 ? "" : s.substr(startingIndex, minLength);
    }
};
