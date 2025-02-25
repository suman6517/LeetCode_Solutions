class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int , int>mpp;
        int k =2;
        int right =0 , left = 0;
        int maxLength =0;

        while(right<fruits.size())
        {
            mpp[fruits[right]]++;
    
                while(mpp.size() > k)
                {
                    mpp[fruits[left]]--;
                    if(mpp[fruits[left]] == 0)
                    {
                        mpp.erase(fruits[left]);
                    }
                    left++;
                }
            if(mpp.size() <=k)
            {
                maxLength =  max(maxLength , right-left+1);

            }
            right++;
        }
        return maxLength;
    }
};