// Compare the input and return the correct value 
int num(char c){
    if(c=='I') return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50;
    else if(c=='D') return 500;
    else if(c=='C') return 100;
    else return 1000;
}

class Solution {
public:
    int romanToInt(string s) {
        int n=s.size(); // size of the string
        int ans=0; // it will calculate ans
        for(int i=0;i<n-1;i++){ 
            if(num(s[i])<num(s[i+1])) ans-=num(s[i]); // calling the num funtion and checking each value of the string whether if smaller then next or not if smaller then do "-" and else "+";
            else ans+=num(s[i]);
        }
        ans+=num(s[n-1]); // add remaining value as we run the loop from 0 to n-2;
        return ans;
    }
};