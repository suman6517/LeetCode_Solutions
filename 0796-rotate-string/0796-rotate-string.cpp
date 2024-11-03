class Solution {
public:
    bool rotateString(string s, string goal)  
    {
        if(s.length() != goal.length())
        {
            return false;
        }
        else if(s == goal)
        {
            return true;
        }
        queue<char>q1 , q2;
        int length =  goal.length()-1;

        for(int i =0; i<length+1; i++)
        {
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        while(length !=0)
        {
            char temp = q1.front();
            q1.pop();
            q1.push(temp);
            if(q1 == q2)
            {
                return true;
            }
            length --;
        }
        return false;
        
    }
};