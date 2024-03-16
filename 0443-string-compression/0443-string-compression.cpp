class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;

        int ansIndex = 0;
        int size = chars.size();

        while (i < size) {
            int j = i + 1;

            while (j < size && chars[j] == chars[i]) {
                j++;
            }

            chars[ansIndex++] = chars[i];

            int total = j - i;

            if (total > 1) {
                string makeChar = to_string(total);

                for (char ch : makeChar) {
                    chars[ansIndex++] = ch;
                }
            }

            i = j;
        }

        return ansIndex;
    }
};