class Solution {
public:
    string largestOddNumber(string num) 
    {
        int size = num.length();
        bool flag = false;
        // stoi convert a string into a Integer ;
        // int number = stoi(num);
         int totalNumber;

        // if(number %2 !=0)
        // {
        //     return num;
            
        // }

        for (int i = size-1 ; i>=0; i--)
        {
           int convertInteger = num[i] - '0';

           if (convertInteger %2 != 0)
           {
            totalNumber = i;
            flag = true;
            break;             
           } 

        }

        if (flag)
        {
            return num.substr(0 , totalNumber+1);
        }
        else
        {
            return "";

        }

        
    }
};