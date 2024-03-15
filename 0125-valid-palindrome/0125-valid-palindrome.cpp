class Solution {

public:
    bool remove_extra(char ch) {
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z' || (ch >= '0' && ch <= '9'))) {
            return 1;

        } else {
            return 0;
        }
    }

    char toLowerCase(char ch) 
    {
       if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
       {
        return ch;
       }

       else
       {
          char temp = (ch-'A' + 'a');
          return temp;
       }

    }

public:
    bool isPalindrome(string s) {
        // Remove the extra element;
        int size = s.length();
        string temp = "";

        for (int i = 0; i < size; i++) {
            if (remove_extra(s[i])) {
                temp.push_back(s[i]);
            }
        }

        // Make all the charcters int the lowercase

        for(int j=0; j<temp.length(); j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }

        // Now check if it is palindrome

        int start = 0;
        int end = temp.length()-1;

        while(start <= end )
        {
            if (temp[start] != temp[end])
            {
                return 0;
            }
            else
            {
                start ++;
                end --;
            }
        }
        return 1;
    }
};