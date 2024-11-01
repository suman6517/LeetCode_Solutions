class Solution {
public:
    string makeFancyString(string &s) 
    {
        int resizeLen=0;
        int len =0;
        char prev = '$';
        for(char c:s)
        {
            if(prev == c)
            {
                len++;
            }
            else
            {
                len =1;
            }
            if(len <=2)
            {
                s[resizeLen++] = c;
                // i++;
            }
            prev =c;
        }
        s.resize(resizeLen);
        return s;

    }
};