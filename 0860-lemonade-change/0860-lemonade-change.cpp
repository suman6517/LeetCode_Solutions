class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int five_dollars = 0;
        int ten_dollars = 0;
        for(int x:bills)
        {
            if(x==5)
            {
                five_dollars ++;
            }
            else if(x == 10)
            {
                if(five_dollars >0)
                {
                    five_dollars -- ;
                    ten_dollars ++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(five_dollars > 0 && ten_dollars > 0)
                {
                    ten_dollars--;
                    five_dollars --;
                }
                else if (five_dollars >=3)
                {
                    five_dollars-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};