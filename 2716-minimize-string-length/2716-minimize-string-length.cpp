class Solution {
public:
    int minimizedStringLength(string s) {
        
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            mp[ch].push_back(i);
        }
        
        return mp.size();
        
    }
};