class Solution {
public:
    string reverseWords(string s) 
    {
        int size = s.length();
        int right = 0;
        int left =0;
        int i = 0;
        reverse(s.begin() , s.end());

        while(i < size)
        {
           while(i <size && s[i] == ' ')
            {
                i++;
            }
            if(i == size)
            {
                break;
            }
            while( i <size && s[i] !=' ')
            {
                s[right] = s[i];
                right++;
                i++;
            }
            reverse(s.begin()+left, s.begin()+right);
            s[right++] = ' ';
            left = right;
            i++;

        }

        s.resize(right-1);

        return s;


        
    }
};  
