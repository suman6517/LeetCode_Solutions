class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
       int stringSize = sentence.size();
       if(sentence[0] != sentence[stringSize-1])
       {
        return false;
       }
       else
       {
        for(int i=0; i<stringSize; i++)
        {
            if(sentence[i] == ' ' &&  sentence[i-1] !=sentence[i+1])
            {
               return false;
            }
        }
       }
       return true;

    }
};