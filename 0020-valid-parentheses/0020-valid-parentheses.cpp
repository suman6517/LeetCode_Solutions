class Solution {
public:
    bool isValid(string str) 
    {
        stack<char>st;
        int i=0;
        while(i < str.length())
        {
            char s = str[i];
            if(s == '(' || s =='{' || s == '[')
            {
                st.push(s);
            }
            else
            {
                if(st.empty() 
                ||
                (s == ')' && st.top()!='(')
                ||
                (s == '}' && st.top()!='{')
                ||
                (s == ']' && st.top()!='[')
                )
                {
                   return false;
                }
                st.pop();
            }
            i++;

        }
        return st.empty();
        
    }
};