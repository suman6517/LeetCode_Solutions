class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        unordered_set<char>row1({'q','w','e','r','t','y','u','i','o','p'});
        unordered_set<char>row2({'a','s','d','f','g','h','j','k','l'});
        unordered_set<char>row3({'z','x','c','v','b','n','m'});

        vector<string>answer={};

        for(auto it:words)
        {
            unordered_set<char>currRow;
            char firstChar = tolower(it[0]);

            if (row1.find(firstChar) != row1.end())
            {
                currRow = row1;
            }
            else if (row2.find(firstChar) != row2.end())
            {
                currRow = row2;
            }
            else
            {
                currRow = row3;
            }

            bool flag = true;
            for (int i =1; i<it.length() ; i++)
            {
                //char currWord = tolower(it[i]);
                if(currRow.find(tolower(it[i])) == currRow.end())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                answer.push_back(it);
            }


        }
        return answer;
        
    }
};