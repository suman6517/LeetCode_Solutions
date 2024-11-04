class Solution {
public:
    string compressedString(string word) 
    {
        int size = word.length();
        string ans = "";
        char ch = word[0];
        int count =1;
        for(int i =1; i<size ; i++)
        {
            if(ch == word[i] && count <9)
            {
                count++;
            }
            else
            {
                ans.push_back(count+'0');
                count =1;
                ans.push_back(ch);
                ch = word[i];
            }
        }
        ans.push_back(count+'0');
        ans.push_back(ch);
        return ans;
        
    }
};