class Solution {
public:
long getstringToInteger(int index , string s, int sign , long result)
{
    if(sign*result >= INT_MAX)
    {
        return INT_MAX;
    }
    else if(sign*result <= INT_MIN)
    {
        return INT_MIN;
    }

    // BASE CASE 
    if(index>=s.length() || s[index]<'0' || s[index]>'9')
    {
        return result*sign;
    }

    result = getstringToInteger(index +1 , s, sign , (result*10+(s[index]-'0')));
    return result;


}


    int myAtoi(string s) 
    {
        int i = 0;
        int sign = 1;
        int size = s.length();
        while (i < size && s[i] == ' ')
        {
            i++;
        }
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }

        return getstringToInteger(i,s,sign, 0);
    }
};