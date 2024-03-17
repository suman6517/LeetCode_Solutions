class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int size = operations.size();
        int ans =0;

        for (int i =0 ; i <size ; i++)
        {
            if (operations[i] == "X++" || operations[i] == "++X" )
            {
                ans = ans+1;
            }
            else
            {
                ans = ans-1;

            }
        }

        return ans ;

        
    }
};