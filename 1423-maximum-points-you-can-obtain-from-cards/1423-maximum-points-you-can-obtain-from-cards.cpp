class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int LeftSum = 0 , MaxSum = 0 , RightSum = 0, RightIndex  = cardPoints.size() -1;
        for(int i =0; i<k; i++){LeftSum += cardPoints[i]; }

        MaxSum = LeftSum;
        for(int i =k-1; i>=0; i--)
        {
            LeftSum -= cardPoints[i];
            RightSum += cardPoints[RightIndex--];
            MaxSum  = max(MaxSum , LeftSum+RightSum);
        }
        return MaxSum;
    }
};