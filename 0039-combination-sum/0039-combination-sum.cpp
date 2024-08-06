class Solution {
public:
void getHelp(vector<vector<int>>&ans , vector<int>&ds , int ind , vector<int>& candidates, int target, int total)
{
    if(target == total)
    {
        ans.push_back(ds);
        return;
    }
    if(ind >= candidates.size() || total >target )
    {
        return ;
    }
    ds.push_back(candidates[ind]);
    getHelp(ans , ds , ind , candidates , target, total+candidates[ind]);
    ds.pop_back();
    getHelp(ans , ds , ind+1 , candidates , target , total);

}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        int ind = 0;
        vector<int>ds;
        int total = 0;
        getHelp(ans , ds , ind , candidates , target , total);
        return ans;
    }
};