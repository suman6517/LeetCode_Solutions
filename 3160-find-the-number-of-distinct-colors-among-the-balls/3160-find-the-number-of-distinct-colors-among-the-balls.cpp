class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int,int>whichColour;
        unordered_map<int,int>howManyColour;
        vector<int>result;

        for (auto iterator : queries)
        {
            if(whichColour.count(iterator[0]))
            {
                int Used = whichColour[iterator[0]];
                howManyColour[Used]--;

                if(howManyColour[Used] == 0)
                {
                    howManyColour.erase(Used);
                }
            }
            whichColour[iterator[0]] = iterator[1];
            howManyColour[iterator[1]]++;

            result.push_back(howManyColour.size());
        }

        return result;
    }
};