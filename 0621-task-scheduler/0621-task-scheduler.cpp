class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        // Calculate the frequency of Each Character 
        vector<int> freq(26, 0);

        // count is the highest frequency character
        int count = 0;
        for(int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
            count = max(count, freq[tasks[i] - 'A']);
        }

        // The minimum length of time to complete the tasks
        int ans = (count - 1) * (n + 1);

        // Add tasks that have the same frequency as the most frequent task
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == count)
            {
                ans++;
            }
        }

        // The answer is either the computed time or the size of the tasks array (whichever is greater)
        return max(ans, (int)tasks.size());
    }
};
