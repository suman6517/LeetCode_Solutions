class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while(!ss.fail()){
            ss>>word;
        }
        return word.size();
    }
};